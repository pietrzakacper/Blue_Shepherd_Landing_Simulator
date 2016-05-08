#pragma once

#include "GameObject.h"
#include <iostream>

class Player :public GameObject
{
	float m_rocketEngineFuel;
	float m_electricity;
	const float m_TRUST = 80.f;
	float gravity;

public:
	Player(std::string texturePath, sf::Vector2f velVec, float fuel, float elect, float grav);
	
	void Update(float, float);
	void CheckEvents(sf::Event&);
};