#include "Player.h"

Player::Player(std::string texturePath, sf::Vector2f velVec, float fuel, float elect, float grav)
	:GameObject(texturePath, velVec),
	gravity(grav)
{
	m_rocketEngineFuel = fuel;
	m_electricity = elect;
}

void Player::Update(float fps, float wind)
{
	m_velocityVector.y += gravity;
	m_velocityVector.x += wind;
	m_sprite.move(m_velocityVector.x * fps, m_velocityVector.y * fps);
}

void Player::CheckEvents(sf::Event & event)
{
	float engineFuelConsuption = 0.1f;
	
	if (event.type == sf::Event::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{

		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (m_rocketEngineFuel - engineFuelConsuption < 0)
			{
				m_rocketEngineFuel = 0;
			}
			else
			{
				m_velocityVector.y -= m_TRUST;
				m_rocketEngineFuel -= engineFuelConsuption;
			}
			
			std::cout << m_rocketEngineFuel << "\n";
		}
	}
}
