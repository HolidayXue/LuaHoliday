#include "AsCInterFace.h"
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <windows.h>

AsCInterFace::AsCInterFace(void)
{
}


AsCInterFace::~AsCInterFace(void)
{
}

void AsCInterFace::test_calledFunction( std::string input_string )
{
	boost::thread thrd(boost::bind(&AsCInterFace::ProcessThreadFunction, this, input_string));
	thrd.detach();
}

void AsCInterFace::ProcessThreadFunction( std::string input_string )
{
	Sleep(5000);
	std::cout<<input_string<<std::endl;
	m_handle(input_string);
}
