#include"Splash.h"
#include"Game.h"
#include"GameState.h"
Splash::Splash()
{
	if (!m_texture.loadFromFile("ASSETS\\splash.jfif"))
	{
		// error...
	}
	m_body.setTexture(&m_texture);
	m_body.setPosition(0, 0);
	m_body.setSize(sf::Vector2f(800, 600));
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
	t_window.draw(m_body);
	t_window.draw(m_message);
	t_window.draw(m_message2);
}

void Splash::loadAssets(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::White);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(48u);
	m_message.setString("Produced\nby\nGreg\n&\nMartin");
	m_message.setFont(m_font);

	m_message2.setFillColor(sf::Color::White);
	m_message2.setPosition(sf::Vector2f{ 550.0f,450.0f });
	m_message2.setCharacterSize(32u);
	m_message2.setString("Press P");
	m_message2.setFont(m_font);
}
