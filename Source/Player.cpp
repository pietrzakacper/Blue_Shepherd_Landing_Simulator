#include "Player.h"

Player::Player(std::string texturePath, sf::Vector2f velVec, float fuel, float elect) :GameObject(texturePath, velVec)
{
	m_rocketEngineFuel = fuel;
	m_electricity = elect;
}

void Player::Update(float fps, float gravity, float wind)
{
	m_sprite.move((m_velocityVector.x += wind) * fps, (m_velocityVector.y += +gravity) * fps);
}

void Player::CheckEvents(sf::Event & event)
{
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

		}
	}
}
