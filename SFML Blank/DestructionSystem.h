#ifndef __DESTRUCT_SYSTEM__
#define __DESTRUCT_SYSTEM__

#include <vector>
#include <memory>

#include "SystemBase.h"
#include "Events.h"

class DestructionSystem : public SystemBase
{
public:
	DestructionSystem(std::vector<std::shared_ptr<GameObject>>* goVecRef) :
		m_goVecRef{ goVecRef }
	{
		registerMember(this, &DestructionSystem::onDestroy);
	}
	void update() override;
private:
	void onDestroy(const DestroyEvent*);
	std::vector<std::shared_ptr<GameObject>>* m_goVecRef;
	std::vector<GameObject*> m_destructionVec;
};

#endif