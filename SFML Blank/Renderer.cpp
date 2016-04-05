#include "Renderer.h"
#include "AutoList.h"
#include "RenderComponent.h"
#include "GameObject.h"

void Renderer::setTexture(const char* fname)
{
	m_texture.loadFromFile(fname);
}


void Renderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.texture = &m_texture;
	sf::VertexArray v;
	v.setPrimitiveType(sf::Quads);
	int size = AutoList<RenderComponent>::size();
	v.resize(size * 4);

	int pos = 0;
	for (int i = 0; i < size; ++i)
	{
		RenderComponent* p = AutoList<RenderComponent>::get(i);
		int tx = p->texturePosition().x;
		int ty = p->texturePosition().y;
		int px = p->parent()->position().x;
		int py = p->parent()->position().y;
		int sx = p->textureSize().x;
		int sy = p->textureSize().y;

		v[pos].position.x = px;
		v[pos].position.y = py;
		v[pos].texCoords.x = tx;
		v[pos].texCoords.y = ty;
		++pos;

		v[pos].position.x = px + sx;
		v[pos].position.y = py;
		v[pos].texCoords.x = tx + sx;
		v[pos].texCoords.y = ty;
		++pos;

		v[pos].position.x = px + sx;
		v[pos].position.y = py + sy;
		v[pos].texCoords.x = tx + sx;
		v[pos].texCoords.y = ty + sy;
		++pos;

		v[pos].position.x = px;
		v[pos].position.y = py + sy;
		v[pos].texCoords.x = tx;
		v[pos].texCoords.y = ty + sy;
		++pos;

	}

	target.draw(v, states);
}