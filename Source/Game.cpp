#include "Game.h"

Game::Game(int width, int height, int fps)
{
	m_window.create(sf::VideoMode(width, height), "Blue Shepherd Landing Simulator | 0.1", sf::Style::Close);
	m_window.setFramerateLimit(fps);

	m_player = new Player("Data/RocketSheet.png", sf::Vector2f(0, 0), 100000, 100000, m_GRAVITY);
	m_background = new GraphicAttributes("Data/Concept.png");
	m_floor = new GraphicAttributes("Data/landingzone.png");
	m_floor->SetPosition(sf::Vector2f((1280 / 2) - m_floor->GetSprite().getGlobalBounds().width / 2, 720 - m_floor->GetSprite().getGlobalBounds().height));
	m_gui = new GUI(width, height, std::string("Data/font.ttf"));
}

void Game::Play()
{
	sf::Clock frameClock;
	sf::Time frameTime;
	sf::Event event;

	srand(time(NULL));


	while(m_window.isOpen())
	{
		m_player->CheckRealTimeEvents();
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window.close();
			}
			m_player->CheckEvents(event);
		}

		handleCollisions(); 

		updateAll(frameTime.asSeconds());
		drawAll();

		frameTime = frameClock.restart();
	}
	
}

void Game::drawAll()
{
	m_window.clear();

	m_window.draw(*m_background);
	m_window.draw(*m_gui);
	m_window.draw(*m_player->partSys);
	m_window.draw(*m_player);

	m_window.draw(*m_floor);
	
	m_window.display();
}

void Game::updateAll(float fps)
{
	m_player->Update(fps, 0);
	m_gui->Update(m_player->GetSprite().getRotation(), m_player->GetVelocityVector().y, sf::Vector2i(25, 345), 150);
}

void Game::handleCollisions()
{
	if (m_player->IsColliding(m_floor->GetSprite()))
	{
		if (m_player->GetSprite().getRotation() > 345.f || m_player->GetSprite().getRotation() < 25.f)
		{
			if (m_player->GetVelocityVector().y >= 150)
			{
				std::cout << "\n\tLadowanie nieudane! (zbyt duza predkosc)\n";
			}

			std::cout << "\n\tLadowanie udane!\n";
		}
		else
		{
			std::cout << "\n\tLadowanie nieudane! (zly kat)\n";
		}
	}
	else if (m_player->GetPosition().y > m_floor->GetPosition().y)
	{
		std::cout << "\n\tLadowanie nieudane! (ominieto platforme)\n";
	}
}

