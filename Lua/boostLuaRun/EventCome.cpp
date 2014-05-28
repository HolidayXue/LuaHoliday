#include "EventCome.h"


EventCome::EventCome()
{
}


EventCome::~EventCome()
{
}

void EventCome::WaitEventCome()
{
	boost::mutex::scoped_lock sl(m_need_wait_mutex);
	m_condition.wait(m_need_wait_mutex);
}

void EventCome::SetEvent()
{
	m_condition.notify_all();
}

void EventCome::TimeWaitEventCome(int wait_million_seconds)
{
	boost::mutex::scoped_lock sl(m_need_wait_mutex);
	
	m_condition.timed_wait(m_need_wait_mutex, boost::get_system_time() + boost::posix_time::microseconds(wait_million_seconds));
}
