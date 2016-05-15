#include "GUI.h"

GUI::GUI(int scrnWidth, int scrnHeight, std::string & fontPath)
{
	m_scrnWidth = scrnWidth;
	m_scrnHeight = scrnHeight;

	m_font.loadFromFile(fontPath);
}

void GUI::Update(int angle, int speed, sf::Vector2i minMaxAngle, int maxSpeed, float elec, float fuel, bool lsDeployed)
{
	m_angle = angle;
	m_speed = speed;
	m_minMaxAngle = minMaxAngle;
	m_maxSpeed = maxSpeed;
	m_fuel = fuel;
	m_electricity = elec;
	m_langingGearDeployed = lsDeployed;
}

void GUI::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	sf::Text angleText("Angle: " + std::to_string(m_angle), m_font);
	sf::Text speedText("Speed: " + std::to_string(m_speed), m_font);
	sf::Text electText("Electricity: " + std::to_string(m_electricity), m_font);
	sf::Text fuelText("Fuel: " + std::to_string(m_fuel), m_font);
	sf::Text landingGearDeployed("Landing gear: \7", m_font);
	
	angleText.setColor(sf::Color::Green);
	speedText.setColor(sf::Color::Green);
	electText.setColor(sf::Color::Green);
	fuelText.setColor(sf::Color::Green);
	landingGearDeployed.setColor(sf::Color::Green);

	if (m_angle > m_minMaxAngle.x && m_angle < m_minMaxAngle.y)
	{
		angleText.setColor(sf::Color::Red);
	}

	if (m_speed > m_maxSpeed)
	{
		speedText.setColor(sf::Color::Red);
	}

	if (m_electricity < 0.1)
	{
		electText.setString(sf::String("Electricity: 0"));
		electText.setColor(sf::Color::Red);
	}

	if (m_fuel < 0.1)
	{
		fuelText.setString(sf::String("Fuel: 0"));
		fuelText.setColor(sf::Color::Red);
	}

	if (!m_langingGearDeployed)
	{
		landingGearDeployed.setColor(sf::Color::Red);
	}

	angleText.setPosition(0, 0);
	speedText.setPosition(0, angleText.getGlobalBounds().height * 1.1);
	electText.setPosition(0, speedText.getPosition().y + speedText.getGlobalBounds().height * 1.1);
	fuelText.setPosition(0, electText.getPosition().y + electText.getGlobalBounds().height * 1.1);
	landingGearDeployed.setPosition(0, fuelText.getPosition().y + fuelText.getGlobalBounds().height * 1.1);

	target.draw(angleText, state);
	target.draw(speedText, state);
	target.draw(electText, state);
	target.draw(fuelText, state);
	target.draw(landingGearDeployed, state);
}
