#pragma once

#include <SFML\Graphics.hpp>
#include <string>

class GUI :public sf::Drawable
{
	int m_scrnWidth;
	int m_scrnHeight;
	sf::Font m_font;

	int m_angle;
	int m_speed;
	sf::Vector2i m_minMaxAngle;
	int m_maxSpeed;
	float m_fuel;
	float m_electricity;
	bool m_langingGearDeployed;

public:
	GUI(int scrnWidth, int scrnHeight, std::string & fontPath);

	void Update(int, int, sf::Vector2i, int, float, float, bool);

private:
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};