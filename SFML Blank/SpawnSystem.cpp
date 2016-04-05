#include "SpawnSystem.h"
#include "GameObject.h"

void SpawnSystem::update()
{
	for (auto& p : m_spawnVec)
	{
		m_goVecRef->push_back(m_factory.makeCell(p.cType));
		(*m_goVecRef)[m_goVecRef->size() - 1]->setPosition(p.x, p.y);
	}
	
	m_spawnVec.clear();
}

void SpawnSystem::onSpawn(const SpawnEvent* evnt)
{
	m_spawnVec.push_back(SpawnData{ evnt->cType(), evnt->x(), evnt->y() });
}