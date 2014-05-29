#pragma once
#ifndef LUARUNNER_H
#define LUARUNNER_H


#include <string>
#include <set>
#include <map>
struct lua_State;

#ifdef  LUASCRIPTVM_API_EXPORTS
#define LUASCRIPTVM_API __declspec(dllexport)
#else
#define LUASCRIPTVM_API __declspec(dllimport)
#endif

// toluapp����.c/.cpp�ļ��е�open��������������ָ����C++�������ࡢ�����ȵ�lua��������
typedef int (*tolua_open_func)(lua_State* tolua_S);

typedef int (*lua_Custom_load) (char *,int , char** ,int* );

class LUASCRIPTVM_API CLuaRunner
{
public:
    CLuaRunner(void);
    ~CLuaRunner(void);

    void SetCustomLoadFunction(lua_Custom_load pFun);
    void AddToluaOpenFunc(tolua_open_func pOpenFunc);

    int InitialiseWorkEnvironment();
    int LoadString(const std::string& pszScript);
    int LoadFile(const std::string& pszScript);

    int DoString(const std::string& pszScript);
    int DoFile(const std::string lpszFilePath);
    
    int CallLuaFunction(const std::string &function_name,const std::string input_JsonString);
    int CallFormatLuaFunction(const std::string &function_name, const char *fmt, ...);
	
    lua_State* GetLuaState();
    
    void Close();
private:
	int CountFormatString(const char*fmt);

    typedef std::set<tolua_open_func> ToLuaOpenFuncArray;
    ToLuaOpenFuncArray m_toluaOpenFuncArray;
};
#endif
