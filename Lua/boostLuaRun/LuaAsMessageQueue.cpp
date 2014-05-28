#include "LuaAsMessageQueue.h"


bool operator<(const LuaMessageNode& first_node, const LuaMessageNode& second_node)
{
	return first_node.m_priority > second_node.m_priority;
}

LuaAsMessageQueue::LuaAsMessageQueue()
{
	
}


LuaAsMessageQueue::~LuaAsMessageQueue()
{
}

void LuaAsMessageQueue::PushMessage(std::string& messageContent, int message_priority)
{
	m_mutex.lock();
	{
		LuaMessageNode tmpNode;
		tmpNode.m_message_content = messageContent;
		tmpNode.m_priority = message_priority;
		m_message_queue.push(tmpNode);
	}
	m_mutex.unlock();
	
}

bool LuaAsMessageQueue::PopMessage(std::string& messageContent)
{
	m_mutex.lock();
	
	bool return_result = false;
	{
		if (!m_message_queue.empty())
		{
			messageContent = m_message_queue.top().m_message_content;
			m_message_queue.pop();
			return_result = true;
		}
		else
		{
			messageContent = "";
			return_result = false;
		}
	}
	
	m_mutex.unlock();
	return return_result;
}

bool LuaAsMessageQueue::IsEmpty()
{
	m_mutex.lock();
	bool return_result = m_message_queue.empty();
	m_mutex.unlock();
	return return_result;
}
