#include "GameObject.h"
#include "IComponent.h"


void GameObject::update()
{
	for (auto& c : m_component)
		c->update();
}

void GameObject::addTag(const char* tag)
{
	m_tag.push_back(tag);
}

bool GameObject::hasTag(const char* tag)
{
	for (auto p : m_tag)
		if (p == tag) return true;

	return false;
}

void GameObject::handleEvent(const EventBase* evnt)
{
	EventHandler::handleEvent(evnt);
	for (auto& p : m_component)
		p->handleEvent(evnt);
}