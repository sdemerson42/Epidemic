#include "Factory.h"
#include "GameObject.h"
#include "BehaviorComponentBlue.h"
#include "BehaviorComponentGreen.h"
#include "BehaviorComponentPurple.h"
#include "BehaviorComponentRed.h"
#include "RenderComponent.h"
#include "HitboxComponent.h"

Factory::Factory()
{
	m_makeMap[CType::Blue] = &Factory::makeBlue;
	m_makeMap[CType::Green] = &Factory::makeGreen;
	m_makeMap[CType::Purple] = &Factory::makePurple;
	m_makeMap[CType::Red] = &Factory::makeRed;
}

std::shared_ptr<GameObject> Factory::makeCell(CType ct)
{
	auto p = m_makeMap.find(ct);
	if (p != m_makeMap.end())
		return (this->*p->second)();
	
	return std::make_shared<GameObject>();
}

std::shared_ptr<GameObject> Factory::makeBlue()
{
	std::shared_ptr<GameObject> p = std::make_shared<GameObject>();
	p->addTag("target");
	p->addComponent<RenderComponent>(30, 0, 30, 30);
	p->addComponent<BehaviorComponentBlue>();
	p->addComponent<HitBoxComponent>(24, 24, 3, 4);
	return p;
}

std::shared_ptr<GameObject> Factory::makeGreen()
{
	std::shared_ptr<GameObject> p = std::make_shared<GameObject>();
	p->addTag("target");
	p->addComponent<RenderComponent>(60, 0, 30, 30);
	p->addComponent<BehaviorComponentGreen>();
	p->addComponent<HitBoxComponent>(24, 24, 3, 4);
	return p;
}

std::shared_ptr<GameObject> Factory::makePurple()
{
	std::shared_ptr<GameObject> p = std::make_shared<GameObject>();
	p->addTag("antibody");
	p->addComponent<RenderComponent>(90, 0, 30, 30);
	p->addComponent<BehaviorComponentPurple>();
	p->addComponent<HitBoxComponent>(24, 24, 3, 4);
	return p;
}

std::shared_ptr<GameObject> Factory::makeRed()
{
	std::shared_ptr<GameObject> p = std::make_shared<GameObject>();
	p->addTag("infector");
	p->addComponent<RenderComponent>(0, 0, 30, 30);
	p->addComponent<BehaviorComponentRed>();
	p->addComponent<HitBoxComponent>(24, 24, 3, 4);
	return p;
}