#include"Intro.h"
#include "GameState.h"
#include "Game.h"
Intro::Intro()
{
}

Intro::~Intro()
{
}

void Intro::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Game::m_currentMode = GameState::splash;
	}
}

void Intro::render(sf::RenderWindow & t_window)
{
	
	t_window.draw(m_message);
	
}

void Intro::loadAssets(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("'B.B.P.G.'\n press space key to go to splashscreen");
	m_message.setFont(m_font);
}
