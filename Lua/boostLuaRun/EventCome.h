#pragma once

#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>
class EventCome
{
public:
	EventCome();
	~EventCome();
	void WaitEventCome();
	void TimeWaitEventCome(int wait_million_seconds);
	void SetEvent();
private:
	boost::mutex m_need_wait_mutex;
	boost::condition m_condition;
};

