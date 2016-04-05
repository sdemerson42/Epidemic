#ifndef __COLLISION_LOGIC__
#define __COLLISION_LOGIC__

#include <vector>
#include <set>

#include "SystemBase.h"

class HitBoxComponent;

class CollisionLogic: public SystemBase
{
public:
	CollisionLogic() :
		m_boxW{ 50 }, m_boxH{ 50 }, m_spaceW{ 800 }, m_spaceH{ 600 }, m_gridW{ m_spaceW / m_boxW }, m_gridH{ m_spaceH / m_boxH } {}
	void update() override;
private:
	bool collision(HitBoxComponent*, HitBoxComponent*);
	void populateGrid();
	void exploreGrid();
	int m_boxW;
	int m_boxH;
	int m_spaceW;
	int m_spaceH;
	int m_gridW;
	int m_gridH;
	std::vector<std::vector<std::vector<HitBoxComponent*>>> m_grid;
	std::set<std::pair<HitBoxComponent*, HitBoxComponent*>> m_checked;
};

#endif