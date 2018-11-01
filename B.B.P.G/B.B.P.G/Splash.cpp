#include"Splash.h"
#include"Game.h"
#include"GameState.h"
Splash::Splash()
{
}

Splash::~Splash()
{
}

void Splash::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		Game::m_currentMode = GameState::mainMenu;
	}
}

void Splash::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_message);
}

void Splash::loadAssets(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("Splash\n press P key to go to mainMenu");
	m_message.setFont(m_font);
}
