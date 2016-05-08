#pragma once

#include "GameObject.h"
#include <iostream>

class Player :public GameObject
{
	float m_rocketEngineFuel;
	float m_electricity;
	const float m_TRUST = 50.f;

public:
	Player(std::string texturePath, sf::Vector2f velVec, float fuel, float elect);
	
	void Update(float, float, float);
	void CheckEvents(sf::Event&);
};