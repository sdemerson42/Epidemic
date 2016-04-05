#ifndef __GAME_STATE__
#define __GAME_STATE__

#include <vector>
#include <memory>

#include "SFML\Graphics.hpp"
#include "EventHandler.h"
#include "Events.h"

class GameObject;
class Renderer;
class CollisionLogic;
class InfectionLogic;
class SoundLogic;
class SystemBase;

class GameState: public sf::Drawable, public sf::Transformable, public EventHandler
{
public:
	GameState(int, int, int, int);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	std::vector<std::shared_ptr<GameObject>> m_gameObject;
	std::shared_ptr<Renderer> m_renderer;
	std::vector<std::shared_ptr<SystemBase>> m_system;
	int m_infectionCounter;
	int m_totalCells;
	void createGameObjects(int, int, int, int);
	void onInfection(const InfectionConfirmEvent*);
};

#endif