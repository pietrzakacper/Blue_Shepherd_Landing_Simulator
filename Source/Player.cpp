#include "Player.h"

Player::Player(std::string texturePath, sf::Vector2f velVec, float fuel, float elect, float grav)
	:GameObject(texturePath, velVec),
	gravity(grav)
{
	m_rocketEngineFuel = fuel;
	m_electricity = elect;
	m_sprite.setPosition((1280 - m_sprite.getGlobalBounds().width) / 2.f, 0);
	m_sprite.setTextureRect(sf::IntRect(58, 0, 58, 134));
	//TODO change pivot here and consider this while checking collisions
}

void Player::Update(float fps, float wind)
{
	m_velocityVector.y += gravity;
	m_velocityVector.x += wind;
	m_sprite.move(m_velocityVector.x * fps, m_velocityVector.y * fps);
	
	if (horizontalInput)
	{
		decreaseElectricity();
		m_sprite.rotate(rotateAngleValue * fps);
	}
	else
	{
		if (m_sprite.getRotation() > 180)m_sprite.rotate(5* fps);
		else if (m_sprite.getRotation() <180)m_sprite.rotate(-5 * fps);
		//TODO enhance rotation and make it relative to Y axis speed
	}

	if (isEngineOn)
		decreaseFuel();
		
	m_velocityVector.x *= 0.95;
	//TODO make user interface 
	std::cout << "Paliwo: " << m_rocketEngineFuel << "\n";
	std::cout << "Elektrycznosc:" << m_electricity << "\n";
	std::cout << "Obrot: " << m_sprite.getRotation() << "\n";
	std::cout << "Predkosc: " << m_velocityVector.y << "\n";
}

void Player::CheckRealTimeEvents()
{
	float engineFuelConsuption = 0.0f;

	//tylko wtedy gdy jest prad
	if (m_electricity > 0)
	{
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
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_rocketEngineFuel)
	{
			
			
		if (m_velocityVector.y > -180.f)
		{
			m_velocityVector.y -= m_TRUST;
		}

		if (!isEngineOn)
		{
			isEngineOn = true;
		}
			
	}
	else
	{
		if (isEngineOn)
		{
			isEngineOn = false;
		}
	}
	
}

void Player::CheckEvents(sf::Event & event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
	{
		m_sprite.setTextureRect(sf::IntRect(0, 0, 58, 134));
	}
	else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
	{
		m_sprite.setTextureRect(sf::IntRect(58, 0, 58, 134));
	}
}

void Player::decreaseFuel()
{
	if (!m_rocketEngineFuel)
	{
		isEngineOn = false;
		return;
	}
	m_rocketEngineFuel -= 0.1f;
}

void Player::decreaseElectricity()
{
	m_electricity -= 1.f;
}
