#include "InfectionLogic.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "HitboxComponent.h"
#include "BehaviorComponentRed.h"

void InfectionLogic::onInfection(const InfectionEvent* evnt)
{
	GameObject* p = static_cast<GameObject*>(evnt->sender());
	for (int i = 0; i < m_infected.size(); ++i)
	{
		if (m_infected[i] == p) return;
	}
	m_infected.push_back(p);
	sendEvent(&InfectionConfirmEvent());
}

void InfectionLogic::onDisinfection(const DisinfectionEvent* evnt)
{
	sendEvent(&DestroyEvent(evnt->target()));
}

void InfectionLogic::update()
{
	for (int i = 0; i < m_infected.size(); ++i)
	{	
		sf::Vector2f pos{ m_infected[i]->position() };	
		sendEvent(&SpawnEvent(Factory::CType::Red, pos.x, pos.y));
		sendEvent(&DestroyEvent(m_infected[i]));
	}
	m_infected.clear();
}