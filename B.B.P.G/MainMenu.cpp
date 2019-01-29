#include"MainMenu.h"
#include "GameState.h"
#include "Game.h"
MainMenu::MainMenu()
{
	for (int i = 0; i < 3; i++)
	{
		m_buttons[i].setFillColor(sf::Color::Blue);
		m_buttons[i].setSize(sf::Vector2f(300, 100));
		m_buttons[i].setOutlineColor(sf::Color::White);
		m_buttons[i].setOutlineThickness(5);
		m_buttons[i].setPosition(400 - 150, 100 + 150 * i);
	}
	m_buttons[buttonHighlighted].setOutlineColor(sf::Color::Red);
}

MainMenu::~MainMenu()
{
}

void MainMenu::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (!pressedOnce)
		{
			m_buttons[buttonHighlighted].setOutlineColor(sf::Color::White);
			buttonHighlighted++;
			if (buttonHighlighted > 2)
			{
				buttonHighlighted = 0;
			}
			m_buttons[buttonHighlighted].setOutlineColor(sf::Color::Red);
			pressedOnce = true;
		}
	}
	count++;
	if (count == 15)
	{
		pressedOnce = false;
		count = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!pressedOnce)
		{
			m_buttons[buttonHighlighted].setOutlineColor(sf::Color::White);
			buttonHighlighted--;
			if (buttonHighlighted < 0)
			{
				buttonHighlighted = 2;
			}
			m_buttons[buttonHighlighted].setOutlineColor(sf::Color::Red);
			pressedOnce = true;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		if (buttonHighlighted == 0)
		{
			Game::m_currentMode = GameState::gameplay;
		}
		if (buttonHighlighted == 1)
		{

		}
		if (buttonHighlighted == 2)
		{
		}
	}
	
}

void MainMenu::render(sf::RenderWindow & t_window)
{
	for (int i = 0; i < 3; i++)
	{
		t_window.draw(m_buttons[i]);
		t_window.draw(m_message[i]);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && buttonHighlighted == 2)
	{
		t_window.close();
	}
}

void MainMenu::loadAssets(sf::Font & t_font)
{
	m_font = t_font;
	for (int i = 0; i < 3; i++)
	{
		m_message[i].setFillColor(sf::Color::Green);
		m_message[i].setPosition(sf::Vector2f{ 400 - 70, 125 + (150.0f * i) });
		m_message[i].setCharacterSize(24u);
		m_message[i].setFont(m_font);
	}
	m_message[0].setString("PLAY");
	m_message[1].setString("OPTIONS");
	m_message[2].setString("EXIT");
}
