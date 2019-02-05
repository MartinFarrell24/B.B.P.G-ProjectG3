#include "Game.h"
GameState Game::m_currentMode{ GameState::intro };

Game::Game() :


m_exitGame{ false }, //when true game will exit
m_window{ sf::VideoMode{ 800, 600, 32 }, "B.B.P.G." }

{
	if (!m_textFont.loadFromFile("ASSETS\\ariblk.ttf"))//load font into m_textFont
	{
		std::cout << "problem loading arial black font" << std::endl;//error
	}

	if (!m_texture.loadFromFile("ASSETS\\rubbishPile.png"))
	{
		// error...
	}

	if (!m_texture2.loadFromFile("ASSETS\\shotgun.png"))
	{
		// error...
	}
	if (!m_doorTexture.loadFromFile("ASSETS\\door.png"))
	{
		// error...
	}

	//pass font to all relevant files
	m_intro.loadAssets(m_textFont);
	m_splash.loadAssets(m_textFont);
	m_mainMenu.loadAssets(m_textFont);
	m_gamePlay.loadAssets(m_textFont);

	m_block[0].setSize(sf::Vector2f(800, 50));
	m_block[0].setPos(sf::Vector2f(0, 550));

	m_block[1].setSize(sf::Vector2f(260, 50));
	m_block[1].setPos(sf::Vector2f(650, 350));

	m_block[2].setSize(sf::Vector2f(490, 50));
	m_block[2].setPos(sf::Vector2f(0, 350));

	m_block[3].setSize(sf::Vector2f(400, 50));
	m_block[3].setPos(sf::Vector2f(400, 500));

	m_block[4].setSize(sf::Vector2f(500, 50));
	m_block[4].setPos(sf::Vector2f(400, 100));

	m_background.setSize(sf::Vector2f(1000, 1000));
	m_background.setPosition(sf::Vector2f(0, 0));
	m_background.setTexture(&m_texture);

	m_shotgun.setTexture(&m_texture2);
	m_shotgun.setSize(sf::Vector2f(50, 50));
	m_shotgun.setPosition(600, 50);

	for (int i = 0; i < 2; i++)
	{
		m_pauseButtons[i].setPosition(350, 125 + 150 * i);
		m_pauseButtons[i].setSize(sf::Vector2f(200, 100));
		m_pauseButtons[i].setOutlineThickness(5);
		m_pauseButtons[i].setOutlineColor(sf::Color::White);
		m_pauseButtons[i].setFillColor(sf::Color::Blue);
	}
	m_pauseButtons[0].setOutlineColor(sf::Color::Red);

	for (int i = 0; i < 2; i++)
	{
		pausedButtonText[i].setFont(m_textFont);
		pausedButtonText[i].setCharacterSize(32u);
		pausedButtonText[i].setOutlineThickness(2);
		pausedButtonText[i].setOutlineColor(sf::Color::White);
		pausedButtonText[i].setFillColor(sf::Color::Red);
		pausedButtonText[i].setPosition(sf::Vector2f(365, 150 + 140 * i));
	}
	pausedButtonText[0].setString("Continue");
	pausedButtonText[1].setString("Quit Game");
	jumpMessage.setFont(m_textFont);
	jumpMessage.setCharacterSize(32u);
	jumpMessage.setFillColor(sf::Color::White);
	jumpMessage.setPosition(sf::Vector2f(10, 200));
	jumpMessage.setString("Press Q to activate powers and jump higher");

	m_door.setSize(sf::Vector2f(60, 100));
	m_door.setPosition(700, 0);
	m_door.setTexture(&m_doorTexture);
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
		if (!gamePaused)
		{
			m_mainMenu.update(t_deltaTime);
		}
		mainMenuTimer++;
		if (mainMenuTimer > 70)
		{
			mainMenuTimer = 0;
			gamePaused = false;
		}
		break;
	case GameState::gameplay:
		if (!gamePaused)
		{
			m_gamePlay.update(t_deltaTime);
			m_player.update(t_deltaTime);
			if (!levelTwo)
			{
				for (int j = 0; j < 5; j++)
				{
					m_slime[j].update(t_deltaTime);
					m_slime[j].turnToPlayer(m_player.getBody().getPosition());

					for (int i = 0; i < 5; i++)
					{

						if (m_player.getBody().getGlobalBounds().intersects(m_block[i].getBody().getGlobalBounds()))
						{
							if (m_player.getBody().getPosition().y > m_block[i].getBody().getPosition().y)
							{
								m_player.setPos(sf::Vector2f(m_player.getBody().getPosition().x, m_player.getBody().getPosition().y + 1));
								m_player.setVelocityToZero();
								m_player.setJumpFalse();
							}
							else if (m_player.getBody().getPosition().y < m_block[i].getBody().getPosition().y)
							{
								m_player.setPos(sf::Vector2f(m_player.getBody().getPosition().x, m_block[i].getBody().getPosition().y - 60));
								m_player.setJumpFalse();
								m_player.setVelocityToZero();
								m_player.setOnBlockTrue();
							}
							if (m_block[i].getBody().getPosition().x + m_block[i].getBody().getGlobalBounds().width < m_player.getBody().getPosition().x)
							{
								m_player.setPos(sf::Vector2f(m_block[i].getBody().getPosition().x + m_block[i].getBody().getGlobalBounds().width, m_player.getBody().getPosition().y));
							}
							if (m_block[i].getBody().getPosition().x > m_player.getBody().getPosition().x + 100)
							{
								m_player.setPos(sf::Vector2f(m_block[i].getBody().getPosition().x, m_player.getBody().getPosition().y));
							}
							if (m_player.getBody().getGlobalBounds().intersects(m_door.getGlobalBounds()))
							{
								m_player.setPos(sf::Vector2f(50, 450));
								levelTwo = true;
							}
						}
						//Slime Section
						if (m_slime[j].getBody().getGlobalBounds().intersects(m_block[i].getBody().getGlobalBounds()))
						{
							if (m_slime[j].getBody().getPosition().y > m_block[i].getBody().getPosition().y)
							{
								m_slime[j].setPos(sf::Vector2f(m_slime[j].getBody().getPosition().x, m_slime[j].getBody().getPosition().y + 1));
								m_slime[j].setVelocityToZero();
								m_slime[j].setJumpFalse();
							}
							else if (m_slime[j].getBody().getPosition().y < m_block[i].getBody().getPosition().y)
							{
								m_slime[j].setPos(sf::Vector2f(m_slime[j].getBody().getPosition().x, m_block[i].getBody().getPosition().y - 30));
								m_slime[j].setJumpFalse();
								m_slime[j].setVelocityToZero();
								m_slime[j].setOnBlockTrue();
							}
							if (m_block[i].getBody().getPosition().x + m_block[i].getBody().getGlobalBounds().width < m_slime[j].getBody().getPosition().x)
							{
								m_slime[j].setPos(sf::Vector2f(m_block[i].getBody().getPosition().x + m_block[i].getBody().getGlobalBounds().width, m_slime[j].getBody().getPosition().y));
							}
							if (m_block[i].getBody().getPosition().x > m_slime[j].getBody().getPosition().x + 1)
							{
								m_slime[j].setPos(sf::Vector2f(m_block[i].getBody().getPosition().x, m_slime[j].getBody().getPosition().y));
							}
						}
						if (m_player.getBody().getGlobalBounds().intersects(m_shotgun.getGlobalBounds()))
						{
							pickedUp = true;
						}
						m_powerBar.update(t_deltaTime);
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
					{
						m_player.setPoweredUpTrue();
					}
					if (m_powerBar.getPowerlevel() < 50)
					{
						m_player.setPoweredUpFalse();
					}
					if (m_player.reducePowerBar() == true)
					{
						m_powerBar.reducePower();
						m_player.stopPowerReduction();
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						gamePaused = true;
					}
				}
			}
		}
		else if (gamePaused)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if (!buttonPressed)
				{
					m_pauseButtons[buttonHighlighted].setOutlineColor(sf::Color::White);
					buttonHighlighted++;
					if (buttonHighlighted > 1)
					{
						buttonHighlighted = 0;
					}
					m_pauseButtons[buttonHighlighted].setOutlineColor(sf::Color::Red);
					buttonPressed = true;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (!buttonPressed)
				{
					m_pauseButtons[buttonHighlighted].setOutlineColor(sf::Color::White);
					buttonHighlighted--;
					if (buttonHighlighted < 0)
					{
						buttonHighlighted = 1;
					}
					m_pauseButtons[buttonHighlighted].setOutlineColor(sf::Color::Red);
					buttonPressed = true;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				if (buttonHighlighted == 0)
				{
					gamePaused = false;
				}
				else if (buttonHighlighted == 1)
				{
					m_currentMode = mainMenu;
				}
			}

			buttonTimer++;
			if (buttonTimer > 20) 
			{
				buttonTimer = 0;
				buttonPressed = false;
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
		m_window.draw(m_background);
		m_gamePlay.render(m_window);
		m_player.render(m_window);
		m_powerBar.render(m_window);

		if (!levelTwo)
		{
			for (int i = 0; i < 5; i++)
			{
				m_block[i].render(m_window);
				m_slime[i].render(m_window);
			}
			m_window.draw(m_door);
		}
		if (levelTwo)
		{
			m_window.draw(jumpMessage);
		}
		if (!pickedUp && !levelTwo)
		{
			m_window.draw(m_shotgun);
		}
		if (gamePaused)
		{
			for (int i = 0; i < 2; i++)
			{
				m_window.draw(m_pauseButtons[i]);
				m_window.draw(pausedButtonText[i]);
			}
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
