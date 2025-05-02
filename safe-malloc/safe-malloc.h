/*
	GNU Lesser General Public License version 2.1
	Copyright (C) 2025 Moises Aguirre "TDRR"

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.
*/
#include <stddef.h>

#ifndef SM_SPC
#define SM_SPC
#endif

[[call("StkCall")]] void SM_SPC *s_malloc (size_t size);
[[call("StkCall")]] void s_free (void SM_SPC *ptr);
[[call("StkCall")]] void SM_SPC *s_realloc (void SM_SPC *oldPtr, size_t size);
[[call("StkCall")]] void SM_SPC *s_calloc (register size_t nmemb, register size_t size);
