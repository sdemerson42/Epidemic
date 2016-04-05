#ifndef __SPAWN_SYSTEM__
#define __SPAWN_SYSTEM__

#include <vector>
#include <memory>

#include "SystemBase.h"
#include "Events.h"

class SpawnSystem : public SystemBase
{
public:
	SpawnSystem(std::vector<std::shared_ptr<GameObject>>* goVecRef) :
		m_goVecRef{ goVecRef }
	{
		registerMember(this, &SpawnSystem::onSpawn);
	}
	void update() override;
private:
	struct SpawnData
	{
		SpawnData(const Factory::CType& ctype, float _x = 0, float _y = 0) :
			cType{ ctype }, x{ _x }, y{ _y }{}
		Factory::CType cType;
		float x;
		float y;
	};
	void onSpawn(const SpawnEvent*);
	std::vector<std::shared_ptr<GameObject>>* m_goVecRef;
	std::vector<SpawnData> m_spawnVec;
	Factory m_factory;
};

#endif