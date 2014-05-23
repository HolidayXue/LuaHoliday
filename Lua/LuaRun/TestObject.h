#pragma once
#include <stdlib.h>
#include "delegate.h"
// tolua_begin
class TestObject
{
public:
    TestObject(void);
    ~TestObject(void);
    
    void print(char* testchar);
// tolua_end
    delegates::CDelegate1<char* > m_DataHandler;
// tolua_begin
};
// tolua_end
