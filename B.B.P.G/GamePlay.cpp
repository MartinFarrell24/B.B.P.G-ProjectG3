#include"GamePlay.h"
#include "GameState.h"
#include "Game.h"
Animations backgroundFactory;
AnimatedSprite background;
Animations* m_CurrentAnim;
GamePlay::GamePlay()
{
	if (!m_texture.loadFromFile("ASSETS\\rubbishPile.png"))
	{
		// error...
	}
	if (!m_facTex.loadFromFile("ASSETS\\level2BackgroundSprite.png"))
	{

	}
	backgroundFactory.setSpriteSheet(m_facTex);
	backgroundFactory.addFrame(sf::IntRect(0, 0, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 801, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 1602, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 2403, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 3204, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 4005, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 4806, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 5607, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 6408, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 7209, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 8010, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 8811, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 9612, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 10413, 800, 600));
	backgroundFactory.addFrame(sf::IntRect(0, 11014, 800, 600));
	//backgroundFactory.addFrame(sf::IntRect(0, 4220, 615, 280));

	background=AnimatedSprite(sf::seconds(0.1), true, false);
	background.setPosition(sf::Vector2f(0,0));
	m_background.setSize(sf::Vector2f(1000, 1000));
	m_background.setPosition(sf::Vector2f(0, 0));
	m_background.setTexture(&m_texture);
	m_CurrentAnim = &backgroundFactory;
}

GamePlay::~GamePlay()
{
}

void GamePlay::update(sf::Time t_deltaTime)
{
	
	background.update(t_deltaTime);
	background.play(*m_CurrentAnim);
	
	background.setLooped(true);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//Game::m_currentMode = GameState::splash;
	}
}

void GamePlay::render(sf::RenderWindow & t_window)
{
	//t_window.draw(m_background);
	t_window.draw(background);
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
