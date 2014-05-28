#ifndef __LUAASMESSAGEQUEUE_H
#define __LUAASMESSAGEQUEUE_H
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>
#include <iostream>
#include <vector>
#include <queue>
#include <string>

struct LuaMessageNode
{
	std::string m_message_content;
	int m_priority;
};
bool operator<(const LuaMessageNode& first_node, const LuaMessageNode& second_node);

class LuaAsMessageQueue
{
public:
	LuaAsMessageQueue();
	~LuaAsMessageQueue();
	enum LuaAsMessagePriority
	{
		LUAMESSAGETOP,
		//添加你自己的lua消息优先级
		//添加你自己的lua消息优先级

		LUAMESSAGEEND,
	};
	bool IsEmpty();
	void PushMessage(std::string&  messageContent, int message_priority = LUAMESSAGEEND);
	bool PopMessage(std::string&  messageContent);
private:
	std::priority_queue<LuaMessageNode, std::deque<LuaMessageNode>> m_message_queue;

	boost::mutex m_mutex;
};


#endif // !__LUAASMESSAGEQUEUE_H