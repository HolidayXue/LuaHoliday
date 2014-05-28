#pragma once
#include <delegate.h>
#include <string>
#include <json.h>
// tolua_begin
class AsCInterFace
{
public:
	AsCInterFace(void);
	~AsCInterFace(void);

	void test_calledFunction(std::string input_string);
// tolua_end
	delegates::CDelegate1<std::string> m_handle;

	void ProcessThreadFunction(std::string input_string);
// tolua_begin
};
// tolua_end
