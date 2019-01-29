#include"Intro.h"
#include "GameState.h"
#include "Game.h"
Intro::Intro()
{
	if (!m_texture.loadFromFile("ASSETS\\.png"))
	{
		// error...
	}
	m_body.setTexture(&m_texture);
	m_body.setPosition(0, 0);
	m_body.setSize(sf::Vector2f(800, 600));
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
	t_window.draw(m_body);
	t_window.draw(m_message);
	t_window.draw(m_message2);
}

void Intro::loadAssets(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 250.0f,50.0f });
	m_message.setCharacterSize(64u);
	m_message.setString("B.B.P.G.");
	m_message.setFont(m_font);

	m_message2.setFillColor(sf::Color::Green);
	m_message2.setPosition(sf::Vector2f{ 50.0f,450.0f });
	m_message2.setCharacterSize(24u);
	m_message2.setString("press space key to go to splashscreen");
	m_message2.setFont(m_font);
	
}
