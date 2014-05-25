#pragma once
#include <stdlib.h>
#include "delegate.h"
#ifdef APICALLEDBYLUA_API_EXPORT
#define APICALLEDBYLUA_API __declspec(dllexport)
#else
#define APICALLEDBYLUA_API __declspec(dllimport)
#endif // 



// tolua_begin
class APICALLEDBYLUA_API TestObject
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
