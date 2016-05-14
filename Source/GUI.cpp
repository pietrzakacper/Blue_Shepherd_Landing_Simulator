#include "GUI.h"

GUI::GUI(int scrnWidth, int scrnHeight, std::string & fontPath)
{
	m_scrnWidth = scrnWidth;
	m_scrnHeight = scrnHeight;

	m_font.loadFromFile(fontPath);
}

void GUI::Update(int angle, int speed, sf::Vector2i minMaxAngle, int maxSpeed)
{
	m_angle = angle;
	m_speed = speed;
	m_minMaxAngle = minMaxAngle;
	m_maxSpeed = maxSpeed;
}

void GUI::draw(sf::RenderTarget & target, sf::RenderStates state) const
{
	sf::Text angleText("Angle: " + std::to_string(m_angle), m_font);
	sf::Text speedText("Speed: " + std::to_string(m_speed), m_font);
	
	if (m_angle < m_minMaxAngle.x || m_angle > m_minMaxAngle.y)
	{
		angleText.setColor(sf::Color::Green);
	}
	else
	{
		angleText.setColor(sf::Color::Red);
	}

	if (m_speed > m_maxSpeed)
	{
		speedText.setColor(sf::Color::Red);
	}
	else
	{
		speedText.setColor(sf::Color::Green);
	}

	angleText.setPosition(0, 0);
	speedText.setPosition(0, angleText.getGlobalBounds().height * 1.1);

	target.draw(angleText, state);
	target.draw(speedText, state);
}
