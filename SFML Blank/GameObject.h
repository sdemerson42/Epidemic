#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include <vector>
#include <memory>
#include <typeindex>

#include "SFML\Graphics.hpp"
#include "AutoList.h"
#include "EventHandler.h"

class IComponent;

class GameObject: public AutoList<GameObject>, public EventHandler
{
public:
	void update();
	template<typename T, typename... Args>
	void addComponent(const Args&... args)
	{
		m_component.push_back(std::make_shared<T>(this, args...));
	}
	template<typename T>
	void removeComponent()
	{
		std::type_index ti(typeid(T));
		for (int i = 0; i < m_component.size(); ++i)
		{
			if (std::type_index(typeid(*m_component[i].get())) == ti)
			{
				m_component.erase(m_component.begin() + i);
				break;
			}
		}
	}
	const sf::Vector2f& position() const { return m_position; }
	void setPosition(float x, float y) { m_position.x = x; m_position.y = y; }
	void addTag(const char*);
	bool hasTag(const char*);
	void handleEvent(const EventBase*);
private:
	std::vector<std::shared_ptr<IComponent>> m_component;
	sf::Vector2f m_position;
	std::vector<const char*> m_tag;
};

#endif