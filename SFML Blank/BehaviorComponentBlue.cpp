#include "BehaviorComponentBlue.h"
#include "GameObject.h"

BehaviorComponentBlue::BehaviorComponentBlue(GameObject* parent) : IComponent{ parent }
{
	registerMember(this, &BehaviorComponentBlue::onCollision);
}

void BehaviorComponentBlue::update()
{
	GameObject* p = nullptr;
	float x = parent()->position().x;
	float y = parent()->position().y;
	for (int i = 0; i < AutoList<GameObject>::size(); ++i)
	{
		p = AutoList<GameObject>::get(i);
		if (p != parent() && abs(p->position().x - x) < 40 && abs(p->position().y - y) < 40)
			break;
		p = nullptr;
	}

	if (p != nullptr)
	{
		float px = p->position().x;
		float py = p->position().y;
		if (x > px) x += 3.0f;
		if (x < px) x -= 3.0f;
		if (y > py) y += 3.0f;
		if (y < py) y -= 3.0f;

		if (x > 770) x = 770.0f;
		if (x < 0) x = 0;
		if (y > 570) y = 570.0f;
		if (y < 0) y = 0;

		parent()->setPosition(x, y);
	}

}

void BehaviorComponentBlue::onCollision(const CollisionEvent* c)
{
	if (c->collider()->hasTag("infector"))
		sendEvent(&InfectionEvent(parent()));
}