#pragma once
#include <SFML\Graphics.hpp>

class Particle
{
public:
	Particle();

	sf::Vector2f velocity;

	sf::Time lifetime;
	
};