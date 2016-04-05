#include "CollisionLogic.h"
#include "HitboxComponent.h"
#include "GameObject.h"
#include "Events.h"

void CollisionLogic::update()
{
	populateGrid();
	exploreGrid();
}

void CollisionLogic::populateGrid()
{
	// Reset grid and check vectors...

	m_grid.clear();
	m_grid.resize(m_gridW);
	
	for (int i = 0; i < AutoList<HitBoxComponent>::size(); ++i)
	{
		auto p = AutoList<HitBoxComponent>::get(i);
		int pgx = (p->parent()->position().x + p->offset().x) / m_boxW;
		int pgy = (p->parent()->position().y + p->offset().y) / m_boxH;
		int pgxx = (p->parent()->position().x + p->offset().x + p->hitBox().x) / m_boxW;
		int pgyy = (p->parent()->position().y + p->offset().y + p->hitBox().y) / m_boxH;


		for (int i = pgx; i <= pgxx; ++i)
		{
			for (int j = pgy; j <= pgyy; ++j)
			{
				if (m_grid[i].size() == 0)
					m_grid[i].resize(m_gridH);
				m_grid[i][j].push_back(p);
			}
		}
	}
}

void CollisionLogic::exploreGrid()
{
	m_checked.clear();
	
	for (int i = 0; i < m_grid.size(); ++i)
	{
		for (int j = 0; j < m_grid[i].size(); ++j)
		{
			for (int m = 0; m < m_grid[i][j].size(); ++m)
			{
				for (int n = m + 1; n < m_grid[i][j].size(); ++n)
				{
					auto p1 = m_checked.find
						(std::pair<HitBoxComponent*, HitBoxComponent*>(m_grid[i][j][m], m_grid[i][j][n]));
					auto p2 = m_checked.find
						(std::pair<HitBoxComponent*, HitBoxComponent*>(m_grid[i][j][n], m_grid[i][j][m]));
					if (p1 == m_checked.end() && p2 == m_checked.end())
					{
						m_checked.insert(std::pair<HitBoxComponent*, HitBoxComponent*>(m_grid[i][j][m], m_grid[i][j][n]));

						if (collision(m_grid[i][j][m], m_grid[i][j][n]))
						{
							m_grid[i][j][m]->parent()->handleEvent(&CollisionEvent(m_grid[i][j][n]->parent(), m_grid[i][j][m]->parent()));
							m_grid[i][j][n]->parent()->handleEvent(&CollisionEvent(m_grid[i][j][m]->parent(), m_grid[i][j][n]->parent()));
						}
					}
				}
			}
		}
	}
}

bool CollisionLogic::collision(HitBoxComponent* p1, HitBoxComponent* p2)
{
	float test = sqrt(3.5f * 2.3f + 2.5f * 4.7f);
	if (!p1->active() || !p2->active()) return false;

	float x1 = p1->parent()->position().x + p1->offset().x;
	float y1 = p1->parent()->position().y + p1->offset().y;
	float w1 = p1->hitBox().x;
	float h1 = p1->hitBox().y;

	float x2 = p2->parent()->position().x + p2->offset().x;
	float y2 = p2->parent()->position().y + p2->offset().y;
	float w2 = p2->hitBox().x;
	float h2 = p2->hitBox().y;

	if (x1 > x2 - w1 && x1 < x2 + w2 && y1 > y2 - h1 && y1 < y2 + h2) 
		return true;

	return false;
}