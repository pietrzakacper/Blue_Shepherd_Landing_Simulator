#include "Player.h"

Player::Player(std::string texturePath, sf::Vector2f velVec, float fuel, float elect, float grav)
	:GameObject(texturePath, velVec),
	gravity(grav)
{
	m_rocketEngineFuel = fuel;
	m_electricity = elect;
	m_sprite.setPosition((1280 - m_sprite.getGlobalBounds().width) / 2.f, 0);
	defaultRotation = m_sprite.getRotation();
	m_sprite.setTextureRect(sf::IntRect(58, 0, 58, 134));
}

void Player::Update(float fps, float wind)
{
	m_velocityVector.y += gravity;
	m_velocityVector.x += wind;
	m_sprite.move(m_velocityVector.x * fps, m_velocityVector.y * fps);
	
	if (horizontalInput)
	{
		m_sprite.rotate(rotateAngleValue * fps);
	}

	else
	{
		if (m_sprite.getRotation() > 180)m_sprite.rotate(5 * fps);
		else if (m_sprite.getRotation() <180)m_sprite.rotate(-5 * fps);
	}

	decreaseFuel();
	decreaseElectricity();
	
	m_velocityVector.x *= 0.95;
	
	if ((isEngineOn && !isEngineOnTextureShowed) || (!isEngineOn && isEngineOnTextureShowed))
	{
		m_sprite.setTextureRect(sf::IntRect(static_cast<int>(!isEngineOn) * 58, 0, 58, 134));
		if (isEngineOn)isEngineOnTextureShowed = true;
		else isEngineOnTextureShowed = false;
	}
	
	std::cout << "Paliwo: " << m_rocketEngineFuel << "\n";
	std::cout << "Elektrycznosc:" << m_electricity << "\n";
	std::cout << "Obrot: " << m_sprite.getRotation() << "\n";
	std::cout << "Predkosc: " << m_velocityVector.y << "\n";
}

void Player::CheckEvents()
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//tylko wtedy gdy jest paliwo
			if (!m_rocketEngineFuel <= 0)
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
		}
		else
		{
			if (isEngineOn)
			{
				isEngineOn = false;
			}
		}
	}
}

void Player::decreaseFuel()
{
	float engineFuelConsuption = 0.1;

	if (isEngineOn)
	{
		if (m_rocketEngineFuel - engineFuelConsuption < 0)
		{
			m_rocketEngineFuel = 0;
			isEngineOn = false;
		}
		else
		{
			m_rocketEngineFuel -= engineFuelConsuption;
		}
	}
}

void Player::decreaseElectricity()
{
	float value = 0.1;

	//jesli jest poruszany to odejmuje wieksza wartosc
	if (horizontalInput)
	{
		value += 1.f;
	}

	m_electricity -= value;
}
