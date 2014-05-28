#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>
#include <iostream>
#include <vector>
#include <queue>
#include <string>


#include <Windows.h>
#include <json.h>

#include <TemplateObjectRegister.h>
#include <LuaRunner.h>
#include <TestObjectBind.h>
#include <TestObject.h>

#include "LuaAsMessageQueue.h"
#include "EventCome.h"


LuaRegisterGlobalObject_ByHoliday(TestObject,G_TestObject1)
LuaRegisterGlobalObject_ByHoliday(TestObject,G_TestObject2)

LuaAsMessageQueue test_messagequeue;
EventCome test_event;

void writer1()
{
	while (1)
	{
		//std::cout << "enter something :\n" << "last input  :";
		std::vector<std::string> tmp_vector;
		tmp_vector.push_back("1 string");
		tmp_vector.push_back("2 string");
		tmp_vector.push_back("3 string");
		tmp_vector.push_back("4 string");
		/*std::string tmp("");
		std::cin >> tmp;
		int tmp_priority;
		std::cout << "enter something priority:\n" ;

		std::cin >> tmp_priority;
		std::cout << "\n";*/
		for (int i = 0; i < tmp_vector.size();i++)
		{
			int i_priroty = i+1;
			if (i==3)
			{
				i_priroty = 1;
			}
			test_messagequeue.PushMessage(tmp_vector[i], i_priroty);
			test_event.SetEvent();
		}
		Sleep(1);
	}
}


void reader1()
{
	while (1)
	{
		test_event.WaitEventCome();

		while (!test_messagequeue.IsEmpty())
		{
			std::string output_string("");
			test_messagequeue.PopMessage(output_string);

			std::cout << output_string << "\n";
		}
		std::cout << "\n";
		Sleep(1);
	}
}

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


	memcpy((*output_buffer_address),input_buffer,input_buffer_size*sizeof(char));
	(*poutput_buffer_size) = input_buffer_size;
	return 0;
}

void main()
{
	/*boost::thread trd1(&writer1);
	boost::thread trd2(&reader1);
	trd1.join();
	trd2.join();*/


	std::string strContent = "{\"function_name\":\"test_call_first\",\"param\":\"{\"email\":\"362783516@qq.com\",\"name\":\"HolidayXue\"}\"}";

	Json::Reader reader;

	Json::Value value;

	if (reader.parse(strContent, value))
	{
		if (value["key1"].empty())
		{
			std::cout<<"key1 not found"<<"\n";
		}
		
		std::string out = value["function_name"].asString();
		std::cout<<out<<"\n";
	}
	CLuaRunner tmp_Runner;
	TestObject test1;
	TestObject test2;
	std::cout<<"input your need run lua:\n";
	/* ÔËÐÐ½Å±¾ */
	std::string input_fileName;
	std::cin>>input_fileName;
	tmp_Runner.SetCustomLoadFunction(CustomLoadLuaScript);
	tmp_Runner.InitialiseWorkEnvironment();

	test1.m_DataHandler = newDelegate(TestObject1_PrintFunction);
	test2.m_DataHandler = newDelegate(TestObject2_PrintFunction);

	LuaRegistObjectFunction_ByHoliday(TestObject,G_TestObject1,tmp_Runner.GetLuaState(),&test1);
	LuaRegistObjectFunction_ByHoliday(TestObject,G_TestObject2,tmp_Runner.GetLuaState(),&test2);

	tmp_Runner.DoFile(input_fileName);
	tmp_Runner.CallLuaFunction("test_call_first","hello");
	system("pause");
}