#include "DestructionSystem.h"

void DestructionSystem::update()
{
	for (auto p : m_destructionVec)
	{
		for (int i = 0; i < m_goVecRef->size(); ++i)
		{
			if (m_goVecRef->at(i).get() == p)
			{
				m_goVecRef->erase(m_goVecRef->begin() + i);
				break;
			}
		}
	}
	m_destructionVec.clear();
}

void DestructionSystem::onDestroy(const DestroyEvent* evnt)
{
	m_destructionVec.push_back(evnt->reference());
}