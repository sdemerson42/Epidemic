#include "InfectionLogic.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "HitboxComponent.h"
#include "BehaviorComponentRed.h"

void InfectionLogic::onInfection(const InfectionEvent* evnt)
{
	GameObject* p = static_cast<GameObject*>(evnt->sender());
	m_infected.push_back(p);
}

void InfectionLogic::onDisinfection(const DisinfectionEvent* evnt)
{
	GameObject* p = static_cast<GameObject*>(evnt->target());
	m_disinfected.push_back(p);
}

void InfectionLogic::update()
{

	GameObject* p = nullptr;
	int goIndex = 0;
	for (int i = 0; i < m_infected.size(); ++i)
	{
		goIndex = 0;
		for (int j = 0; j < m_goVecRef->size(); ++j)
		{
			p = m_goVecRef->at(j).get();
			if (p == m_infected[i]) break;
			p = nullptr;
			++goIndex;
		}
		if (p != nullptr)
		{
			sf::Vector2f pos{ m_infected[i]->position() };
			m_goVecRef->erase(m_goVecRef->begin() + goIndex);
			
			m_goVecRef->push_back(std::make_shared<GameObject>());
			m_goVecRef->at(m_goVecRef->size() - 1)->setPosition(pos.x, pos.y);
			m_goVecRef->at(m_goVecRef->size() - 1)->addTag("infector");
			m_goVecRef->at(m_goVecRef->size() - 1)->addComponent<RenderComponent>(0, 0, 30, 30);
			m_goVecRef->at(m_goVecRef->size() - 1)->addComponent<BehaviorComponentRed>();
			m_goVecRef->at(m_goVecRef->size() - 1)->addComponent<HitBoxComponent>(24, 24, 3, 3);	
		}
	}
	m_infected.clear();

	for (auto p : m_disinfected)
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
	m_disinfected.clear();
}