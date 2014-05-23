#include "TestObject.h"
#include <stdio.h>

TestObject::TestObject(void)
{
}

TestObject::~TestObject(void)
{
}

void TestObject::print( char* testchar )
{
    m_DataHandler(testchar);
}
