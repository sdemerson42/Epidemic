#ifndef __CELL_FACTORY__
#define __CELL_FACTORY__

#include <map>
#include <memory>

class GameObject;

class Factory
{
public:
	Factory();
	static enum class CType { Blue, Green, Purple, Red };
	std::shared_ptr<GameObject> makeCell(CType);
private:
	std::map<CType, std::shared_ptr<GameObject> (Factory::*)()> m_makeMap;
	std::shared_ptr<GameObject> makeBlue();
	std::shared_ptr<GameObject> makeGreen();
	std::shared_ptr<GameObject> makePurple();
	std::shared_ptr<GameObject> makeRed();
};

#endif