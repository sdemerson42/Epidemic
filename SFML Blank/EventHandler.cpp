#include "EventHandler.h"
#include "Events.h"

void EventHandler::handleEvent(const EventBase* evnt)
{
	auto p = m_handlerMap.find(std::type_index(typeid(*evnt)));
	if (p != m_handlerMap.end())
		p->second->call(evnt);
}

void EventHandler::sendEvent(const EventBase* evnt)
{
	for (int i = 0; i < AutoList<EventHandler>::size(); ++i)
	{
		EventHandler* p = AutoList<EventHandler>::get(i);
		if (evnt->receiver() == nullptr)
			p->handleEvent(evnt);
		else
			if (evnt->receiver() == p)
			{
				p->handleEvent(evnt);
				break;
			}
	}
}