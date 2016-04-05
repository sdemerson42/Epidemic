#ifndef __RENDER_COMPONENT__
#define __RENDER_COMPONENT__

#include "IComponent.h"
#include "AutoList.h"
#include "SFML/graphics.hpp"

class GameObject;

class RenderComponent : public IComponent, public AutoList < RenderComponent >
{
public:
	RenderComponent(GameObject* parent, int xPos, int yPos, int xSize, int ySize) : 
		IComponent{ parent }, m_texturePosition{ xPos, yPos }, m_textureSize{ xSize, ySize }{}
	const sf::Vector2i& texturePosition() const { return m_texturePosition; }
	const sf::Vector2i& textureSize() const { return m_textureSize; }
	void update() override {}
private:
	sf::Vector2i m_texturePosition;
	sf::Vector2i m_textureSize;
};

#endif