#pragma once

#include <SFML\Graphics.hpp>

class PhysicAttributes
{
protected:
	sf::Vector2f m_velocityVector;
	
public:
	PhysicAttributes(sf::Vector2f velVec = sf::Vector2f(0,0));

	sf::Vector2f GetVelocityVector();

	void SetVelocityVector(sf::Vector2f);

	virtual void Update(float, float, float) = 0;
};

