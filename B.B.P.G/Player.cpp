#include"Player.h"
#include <iostream>
Player::Player()
{
	if (!m_texture.loadFromFile("ASSETS/_SPRITES/falcon.png"))
	{
		std::cout << "Failed to load player spritesheet!" << std::endl;
		
	}

	m_pos = sf::Vector2f(200, 530);
	m_player.setSize(sf::Vector2f(100, 70));
	m_player.setFillColor(sf::Color::Red);
	m_player.setPosition(m_pos.x, m_pos.y);
	m_gravity = sf::Vector2f(0, 9.8f * m_mass);
	m_velocity = sf::Vector2f(0, -10);
	walkingRight.setSpriteSheet(m_texture);
	walkingRight.addFrame(sf::IntRect(465, 110, 50, 60));
	walkingRight.addFrame(sf::IntRect(518, 110, 50, 60));
	walkingRight.addFrame(sf::IntRect(595, 110, 65, 60));
	walkingRight.addFrame(sf::IntRect(676, 110, 65, 60));
	walkingRight.addFrame(sf::IntRect(308, 110, 65, 60));
	walkingRight.addFrame(sf::IntRect(385, 110, 65, 60));

	walkingLeft.setSpriteSheet(m_texture);
	walkingLeft.addFrame(sf::IntRect(465, 110, 50, 60));
	walkingLeft.addFrame(sf::IntRect(518, 110, 50, 60));
	walkingLeft.addFrame(sf::IntRect(595, 110, 65, 60));
	walkingLeft.addFrame(sf::IntRect(676, 110, 65, 60));
	walkingLeft.addFrame(sf::IntRect(308, 110, 65, 60));
	walkingLeft.addFrame(sf::IntRect(385, 110, 65, 60));
	
	animatedSprite = AnimatedSprite(sf::seconds(0.1), true, false);
	animatedSprite.setPosition(m_player.getPosition());
	m_CurrentAnim = &walkingRight;
	m_grapple.setAnchorRope(sf::Vector2f(200, 400));
}

Player::~Player()
{
}

void Player::update(sf::Time t_deltaTime)
{
	m_grapple.update(t_deltaTime);

	if (sf::Keyboard::isKeyPressed)
	{
		moveLeft();
		moveRight();
		jump(t_deltaTime);
	}
	
	else
	{
		//animatedSprite.stop();
	}
	
	if (m_pos.y >= 520)
	{
		m_jump = false;
		m_velocity = sf::Vector2f(0, -10);
	}
	if (m_pos.x <= 0)
	{
		m_pos.x = 0;
	}
	else if (m_pos.x > 700)
	{
		m_pos.x = 700;
	}
	animatedSprite.setPosition(m_player.getPosition());
	animatedSprite.update(t_deltaTime);
	animatedSprite.play(*m_CurrentAnim);
	animatedSprite.setLooped(true);
}

void Player::render(sf::RenderWindow &t_window)
{
	t_window.draw(animatedSprite);
	
	m_bullet.update(m_player.getPosition());
	if (m_bullet.getIsActive())
	{
		m_bullet.render(t_window);
	}
	m_grapple.render(t_window);
	
	
}

void Player::loadAssets()
{
}

void Player::moveLeft()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_CurrentAnim = &walkingLeft;
		m_pos.x-= 5;
		m_player.setPosition(m_pos.x, m_pos.y);
	}
}

void Player::jump(sf::Time t_deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		
		m_jump = true;
		if (m_velocity != sf::Vector2f(0, -10) && m_onBlock)
		{
			m_velocity = sf::Vector2f(0, -10);
			m_onBlock = false;
		}
	}
	
	if (m_jump)
	{
		m_pos += m_velocity;
		m_pos = m_pos + m_velocity * t_deltaTime.asSeconds() + 0.5f * m_gravity*(t_deltaTime.asSeconds() * t_deltaTime.asSeconds());
		m_velocity = m_velocity + m_gravity * t_deltaTime.asSeconds();
		m_player.setPosition(m_pos.x, m_pos.y);
	}
	else if (!m_jump && m_pos.y <= 520)
	{
		m_pos += m_velocity;
		m_pos = m_pos + m_velocity * t_deltaTime.asSeconds() + 0.5f * m_gravity*(t_deltaTime.asSeconds() * t_deltaTime.asSeconds());
		m_velocity = m_velocity + m_gravity * t_deltaTime.asSeconds();
		m_player.setPosition(m_pos.x, m_pos.y);
	}
}

void Player::moveRight()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_CurrentAnim = &walkingRight;
		m_pos.x+= 5;
		m_player.setPosition(m_pos.x, m_pos.y);
	}
}

sf::RectangleShape Player::getBody()
{
	return m_player;
}

void Player::setPos(sf::Vector2f newPos)
{
	m_pos = newPos;
	m_player.setPosition(m_pos);
}

void Player::setJumpFalse()
{
	m_jump = false;
}

void Player::setVelocity()
{
	m_velocity = sf::Vector2f(0, 2);
}

void Player::setVelocityToZero()
{
	m_velocity = sf::Vector2f(0, 0);
}

void Player::setOnBlockTrue()
{
	m_onBlock = true;
}

void Player::setOnBlockFalse()
{
	m_onBlock = false;
}
