#ifndef __SOUND_LOGIC__
#define __SOUND_LOGIC__

#include "Events.h"
#include "SystemBase.h"
#include "SFML\Audio.hpp"

class SoundLogic: public SystemBase
{
public:
	SoundLogic();
private:
	void onInfection(const InfectionEvent*);
	void onDisinfection(const DisinfectionEvent*);
	sf::SoundBuffer m_sbInfect;
	sf::SoundBuffer m_sbDisinfect;
	sf::Sound m_channel1;
	sf::Sound m_channel2;
};

#endif