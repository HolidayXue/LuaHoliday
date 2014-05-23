#include "LuaCustomAllocateMemory.h"
#include <stdlib.h>

void* XYF_lua_default_alloc (void *ud, void *ptr, size_t osize, size_t nsize) 
{
    (void)ud;
    (void)osize;
    if (nsize == 0) 
    {
        free(ptr);
        return NULL;
    }
    else
    {
        return realloc(ptr, nsize);
    }
};
