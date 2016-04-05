#ifndef __EVENTBASE__
#define __EVENTBASE__

class EventHandler;

class EventBase
{
public:
	EventBase(EventHandler* sender, EventHandler* receiver) :
		m_sender{ sender }, m_receiver{ receiver }{}
	virtual ~EventBase(){}
	EventHandler* sender() const { return m_sender; }
	EventHandler* receiver() const { return m_receiver; }
private:
	EventHandler* m_sender;
	EventHandler* m_receiver;
};

#endif