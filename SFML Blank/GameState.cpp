#include "GameState.h"
#include "GameObject.h"
#include "Renderer.h"
#include "CollisionLogic.h"
#include "InfectionLogic.h"
#include "SoundLogic.h"
#include "DestructionSystem.h"
#include "SpawnSystem.h"
#include "Randutils.h"

#include "RenderComponent.h"
#include "BehaviorComponentRed.h"
#include "BehaviorComponentBlue.h"
#include "BehaviorComponentGreen.h"
#include "BehaviorComponentPurple.h"
#include "HitboxComponent.h"

#include <iostream>

GameState::GameState(int g = 0, int b = 0, int r = 0, int p = 0) :
m_infectionCounter{ 0 }, m_totalCells{ 0 }
{
	m_renderer = std::make_shared<Renderer>();
	m_renderer->setTexture("Assets/swibbles.png");

	m_system.push_back(std::make_shared<CollisionLogic>());
	m_system.push_back(std::make_shared<SoundLogic>());
	m_system.push_back(std::make_shared<InfectionLogic>());
	m_system.push_back(std::make_shared<DestructionSystem>(&m_gameObject));
	m_system.push_back(std::make_shared<SpawnSystem>(&m_gameObject));

	createGameObjects(g,b,r,p);

	registerMember(this, &GameState::onInfection);
}


void GameState::createGameObjects(int g = 0, int b = 0, int r = 0, int p = 0)
{
	m_gameObject.reserve(500);
	BehaviorComponentPurple::init();

	randutils::mt19937_rng rng;

	for (int i = 0; i < r; ++i)
	{
		sendEvent(&SpawnEvent(Factory::CType::Red, float(rng.uniform(0,770)), float(rng.uniform(0,570))));
	}

	for (int i = 0; i < b; ++i)
	{
		sendEvent(&SpawnEvent(Factory::CType::Blue, float(rng.uniform(0, 770)), float(rng.uniform(0, 570))));
		++m_totalCells;
	}

	for (int i = 0; i < g; ++i)
	{
		sendEvent(&SpawnEvent(Factory::CType::Green, float(rng.uniform(0, 770)), float(rng.uniform(0, 570))));
		++m_totalCells;
	}

	for (int i = 0; i < p; ++i)
	{
		sendEvent(&SpawnEvent(Factory::CType::Purple, float(rng.uniform(0, 770)), float(rng.uniform(0, 570))));
	}
}

void GameState::update()
{
	for (auto& p : m_gameObject)
		p->update();

	for (auto& p : m_system)
		p->update();

	// Perctentage infection monitoring, just for fun...

	float k = ((float)m_infectionCounter / (float)m_totalCells) * 100;
	std::cout << k << "%\n";
}

void GameState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	m_renderer->draw(target, states);
}

void GameState::onInfection(const InfectionConfirmEvent* evnt)
{
	++m_infectionCounter;
}