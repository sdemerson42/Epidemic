#ifndef __BEHAVIOR_GREEN__
#define __BEHAVIOR_GREEN__

#include "IComponent.h"
#include "Events.h"

class GameObject;

class BehaviorComponentGreen : public IComponent
{
public:
	BehaviorComponentGreen(GameObject*);
	void update() override;
private:
	void onCollision(const CollisionEvent*);
};

#endif