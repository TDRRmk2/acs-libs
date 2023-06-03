/*
	GNU Lesser General Public License version 2.1
	Copyright (C) 2023 Moises Aguirre "TDRR"

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This file contains some code from libGDCC's alloc.c, written by David Hill.
*/

// Intended to be linked as a replacement to libGDCC.
// (but generally it's perfectly fine to link it dynamically or statically)
#include <ACS_Zandronum.h>
#include <stddef.h>
#include <stdbool.h>

#define BLOCK_TO_PTR(ptr) ((void*)(((char*)ptr) + sizeof(AllocBlockT)))
#define PTR_TO_BLOCK(ptr) ((AllocBlockT*)(((char*)ptr) - sizeof(AllocBlockT)))

enum
{
	// The last 65536 words are used for extra script parameters, so
	// let's avoid those.
	HEAP_START = 0x7FFFFFFF - 65536
};

typedef struct AllocBlock
{
	struct AllocBlock *next;
	size_t size; // we only really need 31-bits unsigned anyway
	bool used : 1;
	bool autBlock : 2;
} AllocBlockT;

typedef struct
{
	bool init;
	int allocTime;
	AllocBlockT *tail, *lastFreed;
} HeapHeadT;

[[call("StkCall")]]
void *s_malloc (register size_t size)
{
	register HeapHeadT *head = (void*)(((char*)HEAP_START) - sizeof(*head));
	register AllocBlockT *block;
	
	if(!head->init)
	{	
		head->init = true;
		head->lastFreed = NULL;
		
		block = (void*)(((char*)head) - (size + sizeof(*block) - 1));
		
		block->autBlock = false;
		block->used = true;
		block->size = size;
		block->next = NULL;
		
		head->tail = block;
		
		return BLOCK_TO_PTR(block);
	}
	
	block = head->tail;
	
	do
	{
		if(block->used || (size > block->size) )
			continue;
		
		#ifdef DEBUG_MODE
			ACS_BeginPrintBold(); ACS_PrintString(s"Found an acceptable block at "); ACS_PrintHex((int)block); ACS_EndPrintBold();
		#endif
		
		// We should split off the block here (4 words is the minimum useful allocation).
		if((block->size - size) >= (sizeof(*block) + 4))
		{	
			AllocBlockT *splitBlock = (void*)(((char*)block) + size + sizeof(*block));
			
			splitBlock->used = false;
			splitBlock->autBlock = false;
			splitBlock->size = block->size - sizeof(*block) - size;
			splitBlock->next = block->next;
			
			block->next = splitBlock;
			block->size = size;
			
			#ifdef DEBUG_MODE
				ACS_BeginPrintBold(); ACS_PrintString(s"Split block "); ACS_PrintHex((int)block); ACS_PrintString(s" to "); ACS_PrintHex((int)splitBlock); ACS_EndPrintBold();
				ACS_BeginPrintBold(); ACS_PrintString(s"next is "); ACS_PrintHex((int)splitBlock->next); ACS_EndPrintBold();
			#endif
		}
		
		block->used = true;
		
		return BLOCK_TO_PTR(block);
		
	} while((block = block->next));
		
	// No acceptable blocks found, so let's "grow" the heap.
	block = (void*)(((char*)head->tail) - (sizeof(*block) + size));
	
	#ifdef DEBUG_MODE
		ACS_BeginPrintBold(); ACS_PrintString(s"Grew the heap for block "); ACS_PrintHex((int)block); ACS_EndPrintBold();
	#endif
	
	block->used = true;
	block->size = size;
	block->next = head->tail;
	
	head->tail = block;
	
	return BLOCK_TO_PTR(block);
}

[[call("StkCall")]]
void s_free (register void *ptr)
{
	if(!ptr)
		return;
	
	register AllocBlockT *block = PTR_TO_BLOCK(ptr);
	
	// Should merge blocks here.
	if( (block->next) && (!block->next->used) )
	{
		#ifdef DEBUG_MODE
			ACS_BeginPrintBold(); ACS_PrintString(s"Merging blocks "); ACS_PrintHex((int)block); ACS_PrintString(s" and "); ACS_PrintHex((int)block->next); ACS_EndPrintBold();
		#endif
		
		block->size += block->next->size + sizeof(*block);
		block->next = block->next->next;
	}
	
	block->used = false;
	block->autBlock = false;
}

[[call("StkCall")]]
void *s_realloc (register void *oldPtr, register size_t size)
{
	if(!oldPtr)
		return (size) ? s_malloc(size) : NULL;
	
	if(!size)
	{
		s_free(oldPtr);
		return NULL;
	}
	
	register AllocBlockT *oldBlock = PTR_TO_BLOCK(oldPtr);
	
	if(size >= oldBlock->size)
		return oldPtr;
	
	register void *ptr = s_malloc(size);
	
	for(int i = 0; i < oldBlock->size; i++)
		((char*)ptr)[i] = ((char*)oldPtr)[i];
	
	s_free(oldPtr);
	
	return ptr;
}

[[call("StkCall")]]
void *s_calloc (register size_t nmemb, register size_t size)
{
	register char *ptr = s_malloc(size *= nmemb);
	
	for(register char *iter = ptr; size--;)
		*iter++ = 0;
	
	return ptr;
}

[[call("StkCall")]]
static void AllocFreeAut (void)
{
	register AllocBlockT *block = ((HeapHeadT*)(((char*)HEAP_START) - sizeof(HeapHeadT)))->tail;
	
	while((block = block->next))
	{
		if(block->used && block->autBlock)
			s_free(block);
	}
}

[[call("ScriptS"), script("open")]]
static void AllocTimeSet(void)
{
   if(!ACS_Timer())
      ACS_Delay(1);

   if(ACS_Timer() == 1)
      ((HeapHeadT*)(((char*)HEAP_START) - sizeof(HeapHeadT)))->allocTime = 1;
}

// AFAICT this function is essentially just realloc so I'll simply call s_realloc for it.
// I *think* this is only called by libc. This also means the libc functions are already
// using the new allocator but we also need to account for anyone not using libc at all (me).
[[call("StkCall")]]
void *__GDCC__alloc (register void *oldPtr, size_t size)
{
	return s_realloc(oldPtr, size);
}

// Internal functions called by GDCC for allocating/freeing the auto stack for every script.
[[call("StkCall")]]
void *__GDCC__Plsa(register unsigned int size)
{
	register int *allocTime = &((HeapHeadT*)(((char*)HEAP_START) - sizeof(HeapHeadT)))->allocTime;
	
	// [DavidPH] Check if a new hub was entered. If so, free automatic storage.
	if(*allocTime > ACS_Timer())
		AllocFreeAut();
	*allocTime = ACS_Timer();
	
	register AllocBlockT *ptr = s_malloc(size);
	
	PTR_TO_BLOCK(ptr)->autBlock = true;
	
	return ptr;
}

[[call("StkCall")]]
void __GDCC__Plsf(void *ptr)
{
	s_free(ptr);
}

// Not sure where this is called from? I'm just using it manually.
[[call("StkCall")]]
void __GDCC__alloc_dump(void)
{
	register AllocBlockT *block = ((HeapHeadT*)(((char*)HEAP_START) - sizeof(HeapHeadT)))->tail;
	
	if(!block)
		return;
	
	do
	{
		ACS_BeginPrint();
		ACS_PrintHex((int)block);
		ACS_PrintString(s" - next: ");
		ACS_PrintHex((int)block->next);
		ACS_PrintString(s", size: ");
		ACS_PrintHex(block->size);
		ACS_PrintString(s", used: ");
		ACS_PrintString((block->used) ? s"true" : s"false");
		ACS_PrintString(s", autBlock: ");
		ACS_PrintString((block->autBlock) ? s"true" : s"false");
		ACS_EndPrint();
	} while((block = block->next));
}