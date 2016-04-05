#ifndef __BEHAVIOR_RED__
#define __BEHAVIOR_RED__

#include "IComponent.h"

class GameObject;

class BehaviorComponentRed: public IComponent
{
public:
	BehaviorComponentRed(GameObject* parent) :
		IComponent{ parent }, m_facing{ 0 }, m_moveCounter{ 0 }, m_moveTotal{ 0 }, m_speed{ 3.0f }{}
	void update() override;
private:
	float m_speed;
	int m_facing;
	int m_moveCounter;
	int m_moveTotal;
	
};

#endif