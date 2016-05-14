#include "Player.h"

Player::Player(std::string texturePath, sf::Vector2f velVec, float fuel, float elect, float grav)
	:GameObject(texturePath, velVec),
	gravity(grav),
	partSys(new ParticleSystem(500))
{
	m_rocketEngineFuel = fuel;
	m_electricity = elect;
	m_sprite.setOrigin(11, 57);
	m_sprite.setPosition(1280/2.f, 0);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 22, 57));
	m_sprite.setScale(sf::Vector2f(2, 2));
	//TODO change pivot here and consider this while checking collisions
	
	m_animationClock.restart();
	m_currentSprite = 1;
}

void Player::Update(float fps, float wind)
{
	changeSprite();
	partSys->SetEmitterPosition(m_sprite.getPosition());
	
	partSys->Update(fps, isEngineOn);
	m_velocityVector.y += gravity;
	m_velocityVector.x += wind;
	m_sprite.move(m_velocityVector.x * fps, m_velocityVector.y * fps);
	
	if (horizontalInput)
	{
		decreaseElectricity();
		m_sprite.rotate(rotateAngleValue * fps );
	}
	else
	{
		if (m_sprite.getRotation() > 359.0f || m_sprite.getRotation() < 1.0f)m_sprite.setRotation(0.f);
		else
		{
		if (m_sprite.getRotation() > 180)m_sprite.rotate(0.05f * fps * fabs(m_velocityVector.y));
		else if (m_sprite.getRotation() < 180)m_sprite.rotate(-0.05f * fps * fabs(m_velocityVector.y));
		//TODO enhance rotation and make it relative to Y axis speed
		}
	}

	if (isEngineOn)
		decreaseFuel();
		
	m_velocityVector.x *= 0.95; 
}

void Player::CheckRealTimeEvents()
{
	float engineFuelConsuption = 0.0f;

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
		//m_sprite.setTextureRect(sf::IntRect(0, 0, 58, 134));
	}
	else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
	{
		//m_sprite.setTextureRect(sf::IntRect(58, 0, 58, 134));
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

void Player::changeSprite()
{
	if (int(m_animationClock.getElapsedTime().asMilliseconds()) > 500 &&
		m_currentSprite <= 5)
	{
		if (m_currentSprite == 1)
		{
			m_sprite.setTextureRect(sf::IntRect(0, 0, 22, 57));
		}
		else if (m_currentSprite == 2)
		{
			m_sprite.setTextureRect(sf::IntRect(23, 0, 22, 57));
		}
		else if (m_currentSprite == 3)
		{
			m_sprite.setTextureRect(sf::IntRect(45, 0, 24, 57));
			m_sprite.setOrigin(12, 57);
		}
		else if (m_currentSprite == 4)
		{
			m_sprite.setTextureRect(sf::IntRect(70, 0, 25, 57));
			m_sprite.setOrigin(13, 57);
		}
		else if (m_currentSprite == 5)
		{
			m_sprite.setTextureRect(sf::IntRect(97, 0, 28, 58));
			m_sprite.setOrigin(14, 57);
		}

		m_sprite.setScale(sf::Vector2f(2, 2));
		m_currentSprite++;
		std::cout << "Time: " << m_animationClock.getElapsedTime().asSeconds() << ", sprite sheet: " << m_currentSprite << "\n";
		m_animationClock.restart();
	}
}
