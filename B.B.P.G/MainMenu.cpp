#include"MainMenu.h"
#include "GameState.h"
#include "Game.h"
MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		Game::m_currentMode = GameState::gameplay;
	}
}

void MainMenu::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_message);
}

void MainMenu::loadAssets(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Main Menu\n press e key to go to gameplay screen");
	m_message.setFont(m_font);
}
