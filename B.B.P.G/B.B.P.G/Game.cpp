#include "Game.h"
GameState Game::m_currentMode{ GameState::gameplay };

Game::Game() :


m_exitGame{ false }, //when true game will exit
m_window{ sf::VideoMode{ 800, 600, 32 }, "B.B.P.G." }

{
	if (!m_textFont.loadFromFile("ASSETS\\ariblk.ttf"))//load font into m_textFont
	{
		std::cout << "problem loading arial black font" << std::endl;//error
	}
	//pass font to all relevant files
	m_intro.loadAssets(m_textFont);
	m_splash.loadAssets(m_textFont);
	m_mainMenu.loadAssets(m_textFont);
	m_gamePlay.loadAssets(m_textFont);

	m_block[0].setSize(sf::Vector2f(150, 20));
	m_block[0].setPos(sf::Vector2f(100, 200));

	m_block[1].setSize(sf::Vector2f(150, 20));
	m_block[1].setPos(sf::Vector2f(400, 300));

	m_block[2].setSize(sf::Vector2f(150, 20));
	m_block[2].setPos(sf::Vector2f(100, 400));

	m_block[3].setSize(sf::Vector2f(150, 20));
	m_block[3].setPos(sf::Vector2f(400, 500));

	m_block[4].setSize(sf::Vector2f(150, 20));
	m_block[4].setPos(sf::Vector2f(400, 100));
}

Game::~Game()
{
	
}

void Game::update(sf::Time t_deltaTime)
{
	
	switch (m_currentMode)//gamestate
	{
	case GameState::intro://no process events for this screen		
		m_intro.update(t_deltaTime);
		break;
	case GameState::splash://no process events for this screen
		m_splash.update(t_deltaTime);
		break;
	case GameState::mainMenu:
		m_mainMenu.update(t_deltaTime);
		break;
	case GameState::gameplay:
		m_gamePlay.update(t_deltaTime);
		m_player.update(t_deltaTime);
		for (int i = 0; i < 5; i++)
		{
			if (m_player.getBody().getGlobalBounds().intersects(m_block[i].getBody().getGlobalBounds()))
			{
				if (m_block[i].getBody().getPosition().y < m_player.getBody().getPosition().y)
				{
					m_player.setPos(sf::Vector2f(m_player.getBody().getPosition().x, m_player.getBody().getPosition().y + 20));
					m_player.setVelocityToZero();
					m_player.setJumpFalse();
				}
				else if (m_block[i].getBody().getPosition().y > m_player.getBody().getPosition().y)
				{
					m_player.setPos(sf::Vector2f(m_player.getBody().getPosition().x, m_block[i].getBody().getPosition().y - 21));
					m_player.setJumpFalse();
					m_player.setVelocityToZero();
					m_player.setOnBlockTrue();
				}
			}
		}
		break;
	default:
		break;
	}
}

void Game::render()
{
	m_window.clear();
	switch (m_currentMode)//gamestate
	{
	case GameState::intro:
		m_intro.render(m_window);
		break;
	case GameState::splash:
		m_splash.render(m_window);
		break;
	case GameState::mainMenu:
		m_mainMenu.render(m_window);
		break;
	case GameState::gameplay:
		m_gamePlay.render(m_window);
		m_player.render(m_window);

		for (int i = 0; i < 5; i++)
		{
			m_block[i].render(m_window);
		}
		break;
	default:
		break;
	}
	m_window.display();
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
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		//m_mainMenu.processEvents();
		//call process events  in certain gamestates
		switch (m_currentMode)//gamestate
		{
		case GameState::intro://no process events for this screen			
			break;
		case GameState::splash://no process events for this screen
			break;
		case GameState::mainMenu:
			//m_mainMenu.processEvents();
			break;
		case GameState::gameplay:
			break;
		default:
			break;
		}
	}
}
