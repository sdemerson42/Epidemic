#ifndef __ICOMPONENT__
#define __ICOMPONENT__

#include "AutoList.h"
#include "EventHandler.h"

class GameObject;

class IComponent: public EventHandler, public AutoList<IComponent>
{
public:
	IComponent(GameObject* parent) : m_parent{ parent }{}
	virtual void update() = 0;
	virtual ~IComponent(){}
	GameObject* parent() const { return m_parent; }
private:
	GameObject* m_parent;
};

#endif