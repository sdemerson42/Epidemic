#ifndef __BEHAVIOR_BLUE__
#define __BEHAVIOR_BLUE__

#include "IComponent.h"
#include "Events.h"

class GameObject;

class BehaviorComponentBlue: public IComponent
{
public:
	BehaviorComponentBlue(GameObject*);
	void update() override;
private:
	void onCollision(const CollisionEvent*);
};

#endif
