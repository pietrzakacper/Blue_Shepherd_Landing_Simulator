#include "Player.h"

Player::Player(std::string texturePath, sf::Vector2f velVec, float fuel, float elect, float grav)
	:GameObject(texturePath, velVec),
	gravity(grav)
{
	m_rocketEngineFuel = fuel;
	m_electricity = elect;
	m_sprite.setPosition((1280 - m_sprite.getGlobalBounds().width) / 2.f, 0);
	defaultRotation = m_sprite.getRotation();
}

void Player::Update(float fps, float wind)
{
	m_velocityVector.y += gravity;
	m_velocityVector.x += wind;
	m_sprite.move(m_velocityVector.x * fps, m_velocityVector.y * fps);
	if(horizontalInput)m_sprite.rotate(rotateAngleValue *fps);
	else
	{
		if (m_sprite.getRotation() > 180)m_sprite.rotate(5 * fps);
		else if (m_sprite.getRotation() <180)m_sprite.rotate(-5 * fps);
	}
	
	m_velocityVector.x *= 0.95;
	
	
}

void Player::CheckEvents()
{
	float engineFuelConsuption = 0.0f;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && m_velocityVector.x > -300.f)
		{
			m_velocityVector.x -= steerForce;
			rotateAngleValue = -20.f;
			horizontalInput = true;
		}
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && m_velocityVector.x < 300.f)
		{
			m_velocityVector.x += steerForce;
			rotateAngleValue = 20.f;
			horizontalInput = true;
		}
		else
		{
			
			horizontalInput = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (m_velocityVector.y > -120.f)m_velocityVector.y -= m_TRUST;

			//if (m_rocketEngineFuel - engineFuelConsuption < 0)
			//{
			//	m_rocketEngineFuel = 0;
			//}
			//else
			//{
			//	
			//	m_rocketEngineFuel -= engineFuelConsuption;
			//}
			//
			//std::cout << m_rocketEngineFuel << "\n";
		}
	
}
