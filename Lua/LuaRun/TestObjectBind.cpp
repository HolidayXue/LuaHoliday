/*
** Lua binding: TestObject
** Generated automatically by tolua++-1.0.92 on 05/23/14 10:56:29.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_TestObject_open (lua_State* tolua_S);

#include "TestObject.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_TestObject (lua_State* tolua_S)
{
 TestObject* self = (TestObject*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"TestObject");
}

/* method: new of class  TestObject */
#ifndef TOLUA_DISABLE_tolua_TestObject_TestObject_new00
static int tolua_TestObject_TestObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TestObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TestObject* tolua_ret = (TestObject*)  Mtolua_new((TestObject)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TestObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  TestObject */
#ifndef TOLUA_DISABLE_tolua_TestObject_TestObject_new00_local
static int tolua_TestObject_TestObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TestObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TestObject* tolua_ret = (TestObject*)  Mtolua_new((TestObject)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TestObject");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  TestObject */
#ifndef TOLUA_DISABLE_tolua_TestObject_TestObject_delete00
static int tolua_TestObject_TestObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TestObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TestObject* self = (TestObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: print of class  TestObject */
#ifndef TOLUA_DISABLE_tolua_TestObject_TestObject_print00
static int tolua_TestObject_TestObject_print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TestObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TestObject* self = (TestObject*)  tolua_tousertype(tolua_S,1,0);
  char* testchar = ((char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'print'", NULL);
#endif
  {
   self->print(testchar);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_TestObject_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"TestObject","TestObject","",tolua_collect_TestObject);
  #else
  tolua_cclass(tolua_S,"TestObject","TestObject","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"TestObject");
   tolua_function(tolua_S,"new",tolua_TestObject_TestObject_new00);
   tolua_function(tolua_S,"new_local",tolua_TestObject_TestObject_new00_local);
   tolua_function(tolua_S,".call",tolua_TestObject_TestObject_new00_local);
   tolua_function(tolua_S,"delete",tolua_TestObject_TestObject_delete00);
   tolua_function(tolua_S,"print",tolua_TestObject_TestObject_print00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_TestObject (lua_State* tolua_S) {
 return tolua_TestObject_open(tolua_S);
};
#endif

