#include "BehaviorComponentRed.h"
#include "GameObject.h"
#include "Randutils.h"


void BehaviorComponentRed::update()
{
	float x = parent()->position().x;
	float y = parent()->position().y;
	switch (m_facing)
	{
	case 0:
		y -= m_speed;
		break;
	case 1:
		y += m_speed;
		break;
	case 2:
		x -= m_speed;
		break;
	case 3:
		x += m_speed;
		break;
	}

	bool bump{ false };

	if (x < 5) 
	{
		x = 5.0f;
		bump = true;
	}
	if (x > 770) 
	{
		x = 770.0f;
		bump = true;
	}
	if (y < 5) 
	{
		y = 5.0f;
		bump = true;
	}
	if (y > 570) 
	{
		y = 570.0f;
		bump = true;
	}

	parent()->setPosition(x, y);
	
	++m_moveCounter;

	if (m_moveCounter >= m_moveTotal || bump)
	{
		randutils::mt19937_rng rng;
		m_moveCounter = 0;
		m_moveTotal = rng.uniform(15,30);
		m_facing = rng.uniform(0, 3);
	}

	
}