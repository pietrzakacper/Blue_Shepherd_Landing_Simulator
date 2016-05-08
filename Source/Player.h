#pragma once

#include "GameObject.h"

class Player :public GameObject
{
	float m_rocketEngineFuel;
	float m_electricity;

public:
	Player(std::string texturePath, sf::Vector2f velVec, float fuel, float elect);
	
	void Update(float, float, float);
	void CheckEvents(sf::Event&);
};