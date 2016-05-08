#include "Game.h"

Game::Game(int width, int height, int fps)
{
	m_window.create(sf::VideoMode(width, height), "Green Shepherd Landing Simulator | 0.1", sf::Style::Close);
	m_window.setFramerateLimit(fps);

	m_player = new Player("Data/test_obj.png", sf::Vector2f(0, 0), 10, 10);
	//Reszta obiektow do wczytania bedzie tutaj...
}

void Game::Play()
{
	sf::Clock frameClock;
	sf::Time frameTime;
	sf::Event event;

	while(m_window.isOpen())
	{ 
		while (m_window.pollEvent(event))
		{
			checkEvents(event);
		}

		//handleCollisions();

		updateAll(frameTime.asSeconds());
		drawAll();

		frameTime = frameClock.restart();
	}
	
}

void Game::drawAll()
{
	m_window.clear();

	m_window.draw(*m_player);

	m_window.display();
}

void Game::updateAll(float fps)
{
	m_player->Update(fps, m_GRAVITY, 0);
}

void Game::checkEvents(sf::Event & event)
{
	if (event.type == sf::Event::Closed)
	{
		m_window.close();
	}

	m_player->CheckEvents(event);
}
