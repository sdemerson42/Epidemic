#include "SoundLogic.h"

SoundLogic::SoundLogic()
{
	m_sbInfect.loadFromFile("Assets/Miss.wav");
	m_sbDisinfect.loadFromFile("Assets/Kill.wav");
	m_channel1.setBuffer(m_sbInfect);
	m_channel2.setBuffer(m_sbDisinfect);
	registerMember(this, &SoundLogic::onInfection);
	registerMember(this, &SoundLogic::onDisinfection);
}

void SoundLogic::onInfection(const InfectionEvent* evnt)
{
	m_channel1.play();
}

void SoundLogic::onDisinfection(const DisinfectionEvent* evnt)
{
	m_channel2.play();
}