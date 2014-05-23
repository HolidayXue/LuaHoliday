#ifndef TEMPLATEOBJECTREGISTER_H
#define TEMPLATEOBJECTREGISTER_H

extern "C" 
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
#include "tolua++.h"
#include <assert.h>
#include <stdio.h>

#define LuaRegisterGlobalObject_ByHoliday(Class_Name_1,LuaObject_Name)  \
        LUA_REGISTER_OBJECT_REGISTER(Class_Name_1,LuaObject_Name)

#define LuaRegistObjectFunction_ByHoliday(Class_Name_1,LuaObject_Name,L,ObjectPtr)  \
        LuaRegistObjectFunction1(Class_Name_1,LuaObject_Name,L,ObjectPtr)


#include "TemplateObjectRegisterImp.h"



#endif