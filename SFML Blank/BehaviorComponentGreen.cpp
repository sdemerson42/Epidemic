#include "BehaviorComponentGreen.h"
#include "GameObject.h"
#include "Randutils.h"


BehaviorComponentGreen::BehaviorComponentGreen(GameObject* parent) : IComponent{ parent }
{
	registerMember(this, &BehaviorComponentGreen::onCollision);
}

void BehaviorComponentGreen::update()
{
	
	float x = parent()->position().x;
	float y = parent()->position().y;
	
	randutils::mt19937_rng rng;

	int r = rng.uniform(0,2);
	if (r == 0) x += 2.0f;
	if (r == 1) x -= 2.0f;

	r = rng.uniform(0, 2);
	if (r == 0) y += 2.0f;
	if (r == 1) y -= 2.0f;

	if (x > 770) x = 770.0f;
	if (x < 0) x = 0;
	if (y > 570) y = 570.0f;
	if (y < 0) y = 0;

	parent()->setPosition(x, y);

}

void BehaviorComponentGreen::onCollision(const CollisionEvent* c)
{
	if (c->collider()->hasTag("infector"))
		sendEvent(&InfectionEvent(parent()));
}