#ifndef __EVENTS__
#define __EVENTS__

#include "EventBase.h"
#include "Factory.h"

class GameObject;

class CollisionEvent : public EventBase
{
public:
	CollisionEvent(GameObject* collider, EventHandler* sender = nullptr, EventHandler* receiver = nullptr) :
		EventBase{ sender, receiver }, m_collider{ collider }{}
	GameObject* collider() const { return m_collider; }
private:
	GameObject* m_collider;
};

class InfectionEvent : public EventBase
{
public:
	InfectionEvent(EventHandler* sender, EventHandler* receiver = nullptr) :
		EventBase{ sender, receiver } {}
};

class InfectionConfirmEvent : public EventBase
{
public:
	InfectionConfirmEvent(EventHandler* sender = nullptr, EventHandler* receiver = nullptr) :
		EventBase{ sender, receiver } {}
};

class DisinfectionEvent : public EventBase
{
public:
	DisinfectionEvent(GameObject* target, EventHandler* sender = nullptr, EventHandler* receiver = nullptr) :
		EventBase{ sender, receiver }, m_target{ target } {}
	GameObject* target() const { return m_target; }
private:
	GameObject* m_target;
};

class DestroyEvent : public EventBase
{
public:
	DestroyEvent(GameObject* ref, EventHandler* sender = nullptr, EventHandler* receiver = nullptr) :
		EventBase{ sender, receiver }, m_ref{ ref }{}
	GameObject* reference() const { return m_ref; }
private:
	GameObject* m_ref;
};

class SpawnEvent : public EventBase
{
public:
	SpawnEvent(Factory::CType ctype, float x = 0.0f, float y = 0.0f, EventHandler* sender = nullptr, EventHandler* receiver = nullptr) :
		EventBase{ sender, receiver }, m_cType{ ctype }, m_x{ x }, m_y{ y } {}
	const Factory::CType& cType() const { return m_cType; }
	float x() const { return m_x; }
	float y() const { return m_y; }
private:
	Factory::CType m_cType;
	float m_x;
	float m_y;
};

#endif