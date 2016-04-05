#ifndef __BEHAVIOR_PURPLE__
#define __BEHAVIOR_PURPLE__

#include <vector>

#include "IComponent.h"
#include "Events.h"

class GameObject;

class BehaviorComponentPurple : public IComponent
{
public:
	BehaviorComponentPurple(GameObject*);
	void update() override;
	static void init() { m_target.clear(); }
private:
	void acquireTarget();
	void onCollision(const CollisionEvent*);
	GameObject* m_myTarget;
	static std::vector<GameObject*> m_target;
	float speed() { return 4.0f; }
};

#endif