#include "Game.h"

Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "B.B.P.G." }
{
}

Game::~Game()
{
}

void Game::update(sf::Time t_deltaTime)
{
}

void Game::render()
{
}

void Game::loadAssets()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents()
{
}
