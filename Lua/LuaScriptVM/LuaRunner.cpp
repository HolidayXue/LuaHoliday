#include "LuaRunner.h"

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "LuaCustomAllocateMemory.h"
#include "tolua++.h"

    int (*LuaCustomLoadFunction)(char *,int , char** ,int *) = NULL;
}

CLuaRunner::CLuaRunner(void):
m_pLuaState(NULL)
{
    m_toluaOpenFuncArray.clear();
}

CLuaRunner::~CLuaRunner(void)
{
    m_toluaOpenFuncArray.clear();
}


int CLuaRunner::LoadString( const std::string& pszScript )
{
    if (NULL == m_pLuaState)
        return LUA_ERRERR;
    int ret = luaL_loadstring(m_pLuaState, pszScript.c_str());
    if (ret != 0)
        return ret;
    ret = lua_pcall(m_pLuaState, 0, 0, 0);
    return ret;
}

int CLuaRunner::DoString( const std::string& pszScript )
{
    if (NULL == m_pLuaState)
        return LUA_ERRERR;

    int res = luaL_dostring(m_pLuaState, pszScript.c_str());   
#ifdef _DEBUG_USE_LUA_ERROR
    if(res != 0)
    {
        const char* pszError = lua_tostring(m_pLuaState, -1);
        lua_settop(m_pLuaState,0);
        if (pszError)
        {
            printf("%s",pszError);
        }
    }
#endif // _DEBUG_USE_LUA_ERROR
    return res;
}

int CLuaRunner::InitialiseWorkEnvironment()
{
    lua_State* L = lua_newstate(XYF_lua_default_alloc, this); // lua_newstate 把C的对象传入lua引擎

    int return_result = -1;
    do 
    {
        if(L == NULL)
        {
            break;
        }

        m_pLuaState = L;
        luaL_openlibs(m_pLuaState);
        
        int nFuncCount = m_toluaOpenFuncArray.size();
        if (nFuncCount != 0)
        {
            bool IsError = false;
            for (ToLuaOpenFuncArray::iterator iterator_LuaOpenFun = m_toluaOpenFuncArray.begin();
                iterator_LuaOpenFun != m_toluaOpenFuncArray.end(); iterator_LuaOpenFun++)
            {
                
                if (!(*iterator_LuaOpenFun)(m_pLuaState))
                {
                    IsError = true;
                    break;
                }
            }
            if (IsError)
            {
                break;
            }
        }

        return_result = 0;
    } while (0);
    

    return return_result;
}

void CLuaRunner::AddToluaOpenFunc( tolua_open_func pOpenFunc )
{
    m_toluaOpenFuncArray.insert(pOpenFunc);
}

int CLuaRunner::DoFile( const std::string lpszFilePath )
{
    if (NULL == m_pLuaState)
        return LUA_ERRERR;

  
    return luaL_dofile(m_pLuaState, lpszFilePath.c_str());
}

int CLuaRunner::LoadFile( const std::string& pszScript )
{
    if (pszScript == "" || NULL == m_pLuaState)
        return LUA_ERRERR;

  

    int ret = luaL_loadfile(m_pLuaState, pszScript.c_str());
    if (ret != 0)
        return ret;

    ret = lua_pcall(m_pLuaState, 0, 0, 0);
    return ret;
}

lua_State* CLuaRunner::GetLuaState()
{
    if (NULL!=m_pLuaState)
    {
         return m_pLuaState;
    }
    else
    {
        return NULL;
    }
   
}

void CLuaRunner::SetCustomLoadFunction( lua_Custom_load pFun )
{
    LuaCustomLoadFunction = pFun;
}

void CLuaRunner::Close()
{
    lua_close(m_pLuaState);
}


