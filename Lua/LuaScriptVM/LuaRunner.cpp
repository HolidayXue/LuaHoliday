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
    lua_State* L = lua_newstate(XYF_lua_default_alloc, this); // lua_newstate ��C�Ķ�������lua����

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

int CLuaRunner::CallLuaFunction(const std::string &function_name, const std::string input_JsonString)
{
	int return_ret = 0;
	do
	{
		if (NULL == m_pLuaState)
		{
			return_ret = 1;
			break;
		}
		std::vector<std::string> table_vector;
		table_vector.clear();
		std::string call_function_name = "";
		std::string tmp_sub_string = function_name;
		int idx = -1;
		while ((idx = tmp_sub_string.find(".")) != tmp_sub_string.npos)
		{
			std::string buffer_string = tmp_sub_string;
			std::string input_table_name = tmp_sub_string.substr(0, idx);
			tmp_sub_string = buffer_string.substr(idx + 1);
			table_vector.push_back(input_table_name);
		}
		call_function_name = tmp_sub_string;
		size_t table_vector_size = table_vector.size();
		if (table_vector_size > 0)
		{
			lua_getglobal(m_pLuaState, table_vector[0].c_str());
			for (size_t i = 1; i < table_vector.size(); i++)
			{
				lua_pushstring(m_pLuaState, table_vector[i].c_str());
				lua_gettable(m_pLuaState, -2);
			}

			lua_pushstring(m_pLuaState, call_function_name.c_str());
			lua_gettable(m_pLuaState, -2);
		}
		else
		{
			lua_getglobal(m_pLuaState, function_name.c_str());
		}

		if (!lua_isfunction(m_pLuaState, -1))
		{
			return_ret = -1;
			break;
		}

		lua_pushstring(m_pLuaState, input_JsonString.c_str());

		int return_ret = lua_pcall(m_pLuaState, 1, LUA_MULTRET, 0);
		if (return_ret != 0)
		{
			break;
		}
		return_ret = 0;
	} while (0);
	return return_ret;
}

int CLuaRunner::CallFormatLuaFunction(const std::string &function_name, const char *fmt, ...)
{
	int return_ret = 0;
	do
	{
		if (NULL == m_pLuaState)
		{
			return_ret = 1;
			break;
		}
		std::vector<std::string> table_vector;
		table_vector.clear();
		std::string call_function_name = "";
		std::string tmp_sub_string = function_name;
		int idx = -1;
		while ((idx = tmp_sub_string.find(".")) != tmp_sub_string.npos)
		{
			std::string buffer_string = tmp_sub_string;
			std::string input_table_name = tmp_sub_string.substr(0, idx);
			tmp_sub_string = buffer_string.substr(idx + 1);
			table_vector.push_back(input_table_name);
		}
		call_function_name = tmp_sub_string;
		size_t table_vector_size = table_vector.size();
		if (table_vector_size > 0)
		{
			lua_getglobal(m_pLuaState, table_vector[0].c_str());
			for (size_t i = 1; i < table_vector.size(); i++)
			{
				lua_pushstring(m_pLuaState, table_vector[i].c_str());
				lua_gettable(m_pLuaState, -2);
			}

			lua_pushstring(m_pLuaState, call_function_name.c_str());
			lua_gettable(m_pLuaState, -2);
		}
		else
		{
			lua_getglobal(m_pLuaState, function_name.c_str());
		}

		if (!lua_isfunction(m_pLuaState, -1))
		{
			return_ret = -1;
			break;
		}
		va_list argp;
		va_start(argp, fmt);
		int argp_count =  CountFormatString(fmt);
		lua_pushvfstring(m_pLuaState, fmt, argp);
		va_end(argp);

		int return_ret = lua_pcall(m_pLuaState, argp_count, LUA_MULTRET, 0);
		if (return_ret != 0)
		{
			break;
		}
		return_ret = 0;
	} while (0);
	return return_ret;
}

int CLuaRunner::CountFormatString(const char*fmt)
{
	int n = 0;
	for (;;)
	{
		const char *e = strchr(fmt, '%');
		if (e == NULL)
		{
			break;
		}
		switch (*(e + 1))
		{
			case 's': 
			{
						n += 1;
				break;
			}
			case 'c': 
			{
						n += 1;
				break;
			}
			case 'd':
			{
						n += 1;
				break;
			}
			case 'f': 
			{
						n += 1;
				break;
			}
			case 'p': 
			{
						n += 1;
				break;
			}
			case '%': 
			{
						n += 1;
				break;
			}
			default:
				{
					   n += 1;
				break;
			}
		}
		fmt = e + 2;
	}
	return n;
}
  

