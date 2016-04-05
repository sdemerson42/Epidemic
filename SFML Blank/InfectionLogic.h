#ifndef __INF_LOGIC__
#define __INF_LOGIC__

#include "Events.h"
#include "SystemBase.h"

#include <vector>
#include <memory>

class InfectionLogic: public SystemBase
{
public:
	InfectionLogic()
	{
		registerMember(this, &InfectionLogic::onInfection);
		registerMember(this, &InfectionLogic::onDisinfection);
	}
	void update() override;
private:
	void onInfection(const InfectionEvent*);
	void onDisinfection(const DisinfectionEvent*);
	std::vector<GameObject*> m_infected;
};

#endif