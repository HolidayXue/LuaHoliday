/*
** Lua binding: AsCInterFace
** Generated automatically by tolua++-1.0.92 on 05/28/14 08:56:51.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_AsCInterFace_open (lua_State* tolua_S);

#include "AsCInterFace.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_AsCInterFace (lua_State* tolua_S)
{
 AsCInterFace* self = (AsCInterFace*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"AsCInterFace");
}

/* method: new of class  AsCInterFace */
#ifndef TOLUA_DISABLE_tolua_AsCInterFace_AsCInterFace_new00
static int tolua_AsCInterFace_AsCInterFace_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AsCInterFace",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AsCInterFace* tolua_ret = (AsCInterFace*)  Mtolua_new((AsCInterFace)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AsCInterFace");
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

/* method: new_local of class  AsCInterFace */
#ifndef TOLUA_DISABLE_tolua_AsCInterFace_AsCInterFace_new00_local
static int tolua_AsCInterFace_AsCInterFace_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AsCInterFace",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AsCInterFace* tolua_ret = (AsCInterFace*)  Mtolua_new((AsCInterFace)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AsCInterFace");
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

/* method: delete of class  AsCInterFace */
#ifndef TOLUA_DISABLE_tolua_AsCInterFace_AsCInterFace_delete00
static int tolua_AsCInterFace_AsCInterFace_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AsCInterFace",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AsCInterFace* self = (AsCInterFace*)  tolua_tousertype(tolua_S,1,0);
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

/* method: test_calledFunction of class  AsCInterFace */
#ifndef TOLUA_DISABLE_tolua_AsCInterFace_AsCInterFace_test_calledFunction00
static int tolua_AsCInterFace_AsCInterFace_test_calledFunction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AsCInterFace",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AsCInterFace* self = (AsCInterFace*)  tolua_tousertype(tolua_S,1,0);
  std::string input_string = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'test_calledFunction'", NULL);
#endif
  {
   self->test_calledFunction(input_string);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'test_calledFunction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_AsCInterFace_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"AsCInterFace","AsCInterFace","",tolua_collect_AsCInterFace);
  #else
  tolua_cclass(tolua_S,"AsCInterFace","AsCInterFace","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"AsCInterFace");
   tolua_function(tolua_S,"new",tolua_AsCInterFace_AsCInterFace_new00);
   tolua_function(tolua_S,"new_local",tolua_AsCInterFace_AsCInterFace_new00_local);
   tolua_function(tolua_S,".call",tolua_AsCInterFace_AsCInterFace_new00_local);
   tolua_function(tolua_S,"delete",tolua_AsCInterFace_AsCInterFace_delete00);
   tolua_function(tolua_S,"test_calledFunction",tolua_AsCInterFace_AsCInterFace_test_calledFunction00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_AsCInterFace (lua_State* tolua_S) {
 return tolua_AsCInterFace_open(tolua_S);
};
#endif

