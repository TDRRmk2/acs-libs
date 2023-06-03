/*
	GNU Lesser General Public License version 2.1
	Copyright (C) 2023 Moises Aguirre "TDRR"

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.
*/
#include <stddef.h>

[[call("StkCall")]] void *s_malloc (size_t size);
[[call("StkCall")]] void s_free (void *ptr);
[[call("StkCall")]] void *s_realloc (void *oldPtr, size_t size);
[[call("StkCall")]] void *s_calloc (register size_t nmemb, register size_t size);