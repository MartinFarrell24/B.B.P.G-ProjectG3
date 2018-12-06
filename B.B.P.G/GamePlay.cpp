#include"GamePlay.h"
#include "GameState.h"
#include "Game.h"
GamePlay::GamePlay()
{
	if (!m_texture.loadFromFile("ASSETS\\rubbishPile.png"))
	{
		// error...
	}

	
	m_background.setSize(sf::Vector2f(1000, 1000));
	m_background.setPosition(sf::Vector2f(0, 0));
	m_background.setTexture(&m_texture);
	
}

GamePlay::~GamePlay()
{
}

void GamePlay::update(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//Game::m_currentMode = GameState::splash;
	}
}

void GamePlay::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_background);
	//t_window.draw(m_message);

}

void GamePlay::loadAssets(sf::Font & t_font)
{
	m_font = t_font;
	m_message.setFillColor(sf::Color::Green);
	m_message.setPosition(sf::Vector2f{ 50.0f,50.0f });
	m_message.setCharacterSize(24u);
	m_message.setString("gameplay");
	m_message.setFont(m_font);
}

void GamePlay::setPickedUpTrue()
{
	pickedUp = true;
}
