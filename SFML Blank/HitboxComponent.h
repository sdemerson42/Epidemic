#ifndef __HITBOX_COMPONENT__
#define __HITBOX_COMPONENT__

#include "IComponent.h"
#include "AutoList.h"
#include "SFML\Graphics.hpp"

class GameObject;

class HitBoxComponent: public IComponent, public AutoList<HitBoxComponent>
{
public:
	HitBoxComponent(GameObject* parent, int width, int height, int xOff = 0, int yOff = 0, bool active = true) :
		IComponent{ parent }, m_hitBox{ width, height }, m_offset{ xOff, yOff }, m_active{ active } {}
	const sf::Vector2i& hitBox() const { return m_hitBox; }
	const sf::Vector2i& offset() const { return m_offset; }
	bool active() const { return m_active; }
	void update() override {}
private:
	sf::Vector2i m_hitBox;
	sf::Vector2i m_offset;
	bool m_active;
};


#endif