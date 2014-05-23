#include "TemplateObjectRegister.h"

#define LUA_OBJECT_REGIST_TEMPLATE_COMBINE(a, b)                     LUA_OBJECT_REGIST_TEMPLATE_COMBINE1(a, b)
#define LUA_OBJECT_REGIST_TEMPLATE_COMBINE1(a, b)                    a##b

#define AddQuotationMark2(exp)  AddQuotationMark(exp)
#define AddQuotationMark(exp) (#exp)

#define LUA_ASSERT                                                      LUA_ASSERT1
#define LUA_ASSERT1(x)                                                  assert(x)


#define REGISTER_OBJECT_TO_INNER_STRING(LuaObject_Name)   AddQuotationMark2(\
    LUA_OBJECT_REGIST_TEMPLATE_COMBINE(__,LuaObject_Name))


#define  LuaRegistObjectFunction1(Class_Name_1,LuaObject_Name,L,ObjectPtr)   \
    LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LUA_OBJECT_REGIST_TEMPLATE_COMBINE(Lua_RegisterGlobalObject_,Class_Name_1),\
    LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LuaObject_Name,_ptr_ByHoliday) )\
    (L,ObjectPtr)



int tolua_push_LuaGlobalobject (lua_State* tolua_S, const char* pszName,lua_CFunction get_function_ptr, lua_CFunction set_function_ptr)
{
    tolua_open(tolua_S);
    tolua_module(tolua_S, NULL, 1);
    tolua_beginmodule(tolua_S, NULL);
    tolua_variable(tolua_S, pszName, get_function_ptr, set_function_ptr);
    tolua_endmodule(tolua_S);

    return 1;
}

#define LUA_REGISTER_OBJECT_GET(Class_Name_1,LuaObject_Name)   \
    int LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LUA_OBJECT_REGIST_TEMPLATE_COMBINE(tolua_get_,Class_Name_1),\
    LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LuaObject_Name,_ptr))(lua_State* tolua_S)\
{\
    lua_getglobal(tolua_S,REGISTER_OBJECT_TO_INNER_STRING(LuaObject_Name) );\
    Class_Name_1* pManger = (Class_Name_1*)lua_touserdata(tolua_S,-1);\
    if (pManger)\
{\
    tolua_pushusertype(tolua_S, (void*)pManger, AddQuotationMark2(Class_Name_1) );\
    return 1;\
}\
    else\
{\
    LUA_ASSERT(0);\
    return 1;\
}\
    \
    return 0;\
};
#ifndef TOLUA_RELEASE
#define LUA_REGISTER_OBJECT_SET(Class_Name_1,LuaObject_Name)   \
    int LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LUA_OBJECT_REGIST_TEMPLATE_COMBINE(tolua_set_,Class_Name_1),\
    LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LuaObject_Name,_ptr))(lua_State* tolua_S)\
{\
    \
    \
    tolua_Error tolua_err;\
    if (!tolua_isusertype(tolua_S,2,AddQuotationMark2(Class_Name_1),0,&tolua_err))\
{\
    tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);\
}\
    \
    \
    \
    lua_getglobal(tolua_S,REGISTER_OBJECT_TO_INNER_STRING(LuaObject_Name) );\
    Class_Name_1* pManger = (Class_Name_1*)lua_touserdata(tolua_S,-1);\
    \
    lua_pushlightuserdata(tolua_S,pManger);\
    lua_setglobal(tolua_S,REGISTER_OBJECT_TO_INNER_STRING(LuaObject_Name) );\
    \
    return 0;\
};
#else
#define LUA_REGISTER_OBJECT_SET(Class_Name_1,LuaObject_Name)   \
    int LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LUA_OBJECT_REGIST_TEMPLATE_COMBINE(tolua_set_,Class_Name_1),\
    LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LuaObject_Name,_ptr))(lua_State* tolua_S)\
{\
    lua_getglobal(tolua_S,REGISTER_OBJECT_TO_INNER_STRING(LuaObject_Name) );\
    Class_Name_1* pManger = (Class_Name_1*)lua_touserdata(tolua_S,-1);\
    \
    lua_pushlightuserdata(tolua_S,pManger);\
    lua_setglobal(tolua_S,REGISTER_OBJECT_TO_INNER_STRING(LuaObject_Name) );\
    \
    return 0;\
};
#endif


#define  LUA_REGISTER_OBJECT_REGISTER_PTR(Class_Name_1,LuaObject_Name)   \
    int LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LUA_OBJECT_REGIST_TEMPLATE_COMBINE(Lua_RegisterGlobalObject_,Class_Name_1),\
    LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LuaObject_Name,_ptr_ByHoliday) )\
    (lua_State *L,Class_Name_1* pManger)\
{\
    \
    LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LUA_OBJECT_REGIST_TEMPLATE_COMBINE(tolua_,Class_Name_1),_open)(L);\
    lua_pushlightuserdata(L,pManger);\
    \
    lua_setglobal(L,REGISTER_OBJECT_TO_INNER_STRING(LuaObject_Name));\
    tolua_push_LuaGlobalobject(L,AddQuotationMark2(LuaObject_Name),\
    LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LUA_OBJECT_REGIST_TEMPLATE_COMBINE(tolua_get_,Class_Name_1),\
    LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LuaObject_Name,_ptr)),\
    LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LUA_OBJECT_REGIST_TEMPLATE_COMBINE(tolua_set_,Class_Name_1),\
    LUA_OBJECT_REGIST_TEMPLATE_COMBINE(LuaObject_Name,_ptr)));\
    return 1;\
};

#define LUA_REGISTER_OBJECT_REGISTER(Class_Name_1,LuaObject_Name)\
    LUA_REGISTER_OBJECT_GET(Class_Name_1,LuaObject_Name)\
    LUA_REGISTER_OBJECT_SET(Class_Name_1,LuaObject_Name)\
    LUA_REGISTER_OBJECT_REGISTER_PTR(Class_Name_1,LuaObject_Name)
