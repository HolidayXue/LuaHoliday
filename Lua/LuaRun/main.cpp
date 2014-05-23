#include <stdio.h>
#include <iostream>
#include <string>
#include <LuaRunner.h>
#include <TemplateObjectRegister.h>
#include "TestObjectBind.h"
#include "TestObject.h"


using namespace std;


LuaRegisterGlobalObject_ByHoliday(TestObject,G_TestObject1)

LuaRegisterGlobalObject_ByHoliday(TestObject,G_TestObject2)


void TestObject1_PrintFunction(char* str_input)
{
    printf("This is TestObject1 outPut: %s",str_input);
}

void TestObject2_PrintFunction(char* str_input)
{
    printf("This is TestObject2 outPut: %s",str_input);
}

int CustomLoadLuaScript( char *input_buffer,int input_buffer_size, char** output_buffer_address,int* poutput_buffer_size )
{
    int new_length = input_buffer_size+1;
    (*output_buffer_address) = new char[new_length];
    memset(*output_buffer_address,0,new_length);


    memccpy((*output_buffer_address),input_buffer,sizeof(char),input_buffer_size);
    (*poutput_buffer_size) = input_buffer_size;
    return 0;
}


int main ( int argc, char *argv[] )
{
    /* 初始化Lua */
    CLuaRunner tmp_Runner;
    TestObject test1;
    TestObject test2;
    std::cout<<"input your need run lua:\n";
    /* 运行脚本 */
    std::string input_fileName;
    std::cin>>input_fileName;
    tmp_Runner.SetCustomLoadFunction(CustomLoadLuaScript);
    tmp_Runner.InitialiseWorkEnvironment();
    test1.m_DataHandler = newDelegate(TestObject1_PrintFunction);
    test2.m_DataHandler = newDelegate(TestObject2_PrintFunction);

    LuaRegistObjectFunction_ByHoliday(TestObject,G_TestObject1,tmp_Runner.GetLuaState(),&test1);
    LuaRegistObjectFunction_ByHoliday(TestObject,G_TestObject2,tmp_Runner.GetLuaState(),&test2);

    tmp_Runner.DoFile(input_fileName);
    /* 暂停 */
    system("pause");

    return 0;
}