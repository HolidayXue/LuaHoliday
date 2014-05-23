#ifndef LUACUSTOMALLOCATEMEMORY_H
#define LUACUSTOMALLOCATEMEMORY_H
#include <stdlib.h>

void* XYF_lua_default_alloc(void *ud, void *ptr, size_t osize, size_t nsize); 


#endif