#pragma once

#include "Player.h"
#include "GUI.h";

class Game
{
	sf::RenderWindow m_window;
	Player * m_player;
	GraphicAttributes * m_background;
	GraphicAttributes * m_floor;
	const float m_GRAVITY = 10.f;
	GUI * m_gui;
	
public:
	Game(int width, int height, int fps);

	void Play();

private:
	void drawAll();
	void updateAll(float);
	void handleCollisions();
	//TODO handlefailure
	//TODO handlevictory

};