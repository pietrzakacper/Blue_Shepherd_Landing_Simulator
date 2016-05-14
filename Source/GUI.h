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

public:
	GUI(int scrnWidth, int scrnHeight, std::string & fontPath);

	void Update(int, int, sf::Vector2i, int);

private:
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};