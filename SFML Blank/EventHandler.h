#ifndef __EVENTHANDLER__
#define __EVENTHANDLER__

#include <memory>
#include <map>
#include <typeindex>

#include "EventBase.h"
#include "AutoList.h"

template<typename T, typename EventT>
using MFunc = void(T::*)(const EventT*);

class IMemFuncHandler
{
public:
	virtual void call(const EventBase*) = 0;
};

template<typename T, typename EventT>
class MemFuncHandler : public IMemFuncHandler
{
public:
	MemFuncHandler(T* instance, MFunc<T, EventT> func) :
		m_instance{ instance }, m_func{ func }{}
	void call(const EventBase* evnt) override
	{
		(m_instance->*m_func)(static_cast<const EventT*>(evnt));
	}
private:
	T* m_instance;
	MFunc<T, EventT> m_func;
};

class EventHandler: public AutoList<EventHandler>
{
public:
	template<typename T, typename EventT>
	void registerMember(T* instance, MFunc<T, EventT> func)
	{
		m_handlerMap[std::type_index(typeid(EventT))] = std::make_shared<MemFuncHandler<T, EventT>>(instance, func);
	}
	void handleEvent(const EventBase*);
	void sendEvent(const EventBase*);
private:
	std::map<std::type_index, std::shared_ptr<IMemFuncHandler>> m_handlerMap;
};

#endif