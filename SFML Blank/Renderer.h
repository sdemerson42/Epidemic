#ifndef __RENDERER__
#define __RENDERER__

#include "SFML\Graphics.hpp"

class Renderer : public sf::Drawable, sf::Transformable
{
public:
	void setTexture(const char* fname);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Texture m_texture;
};

#endif