#include "BehaviorComponentPurple.h"
#include "GameObject.h"
#include "AutoList.h"

std::vector<GameObject*> BehaviorComponentPurple::m_target;

BehaviorComponentPurple::BehaviorComponentPurple(GameObject* parent) : IComponent{ parent }, m_myTarget{ nullptr }
{
	registerMember(this, &BehaviorComponentPurple::onCollision);
}


void BehaviorComponentPurple::update()
{

	if (m_myTarget == nullptr)
	{
		acquireTarget();
		return;
	}

	float x = parent()->position().x;
	float y = parent()->position().y;
	float tx = m_myTarget->position().x;
	float ty = m_myTarget->position().y;

	if (x < tx) x += speed();
	if (x > tx) x -= speed();
	if (y < ty) y += speed();
	if (y > ty) y -= speed();

	parent()->setPosition(x, y);

}

void BehaviorComponentPurple::acquireTarget()
{
	if (m_myTarget != nullptr) return;

	double dist = 0;
	GameObject* t = nullptr;

	for (int i = 0; i < AutoList<GameObject>::size(); ++i)
	{
		auto p = AutoList<GameObject>::get(i);
		if (p->hasTag("infector"))
		{
			bool non = false;
			for (auto p2 : m_target)
			{
				if (p2 == p)
				{
					non = true;
					break;
				}
			}
			if (!non)
			{
				double fDist = pow(parent()->position().x - p->position().x, 2) + pow(parent()->position().y - p->position().y, 2);
				if (dist == 0 || fDist < dist)
				{
					dist = fDist;
					t = p;
				}
			}
		}
	}
	m_myTarget = t;
	m_target.push_back(t);
}

void BehaviorComponentPurple::onCollision(const CollisionEvent* c)
{
	if (c->collider() == m_myTarget)
	{
		sendEvent(&DisinfectionEvent(m_myTarget));
		for (int i = 0; i < m_target.size(); ++i)
		{
			if (m_target[i] == m_myTarget)
			{
				m_target.erase(m_target.begin() + i);
				break;
			}
		}
		m_myTarget = nullptr;
	}
}