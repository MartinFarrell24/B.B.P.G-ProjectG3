#include"Player.h"

Player::Player()
{
	m_pos = sf::Vector2f(200, 580);
	m_player.setSize(sf::Vector2f(20, 20));
	m_player.setFillColor(sf::Color::Red);
	m_player.setPosition(m_pos.x, m_pos.y);
	m_gravity = sf::Vector2f(0, 9.8f * m_mass);
	m_velocity = sf::Vector2f(0, -10);
}

Player::~Player()
{
}

void Player::update(sf::Time t_deltaTime)
{
	moveLeft();
	moveRight();
	jump(t_deltaTime);

	if (m_pos.y >= 570)
	{
		m_jump = false;
		m_velocity = sf::Vector2f(0, -10);
	}
	if (m_pos.x <= 0)
	{
		m_pos.x = 0;
	}
	else if (m_pos.x > 780)
	{
		m_pos.x = 780;
	}
}

void Player::render(sf::RenderWindow &t_window)
{
	t_window.draw(m_player);
}

void Player::loadAssets()
{
}

void Player::moveLeft()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_pos.y -= 10;
		m_player.setPosition(m_pos);
		m_jump = true;
		m_velocity = sf::Vector2f(0, -10);
	}
	if (m_jump)
	{
		m_pos += m_velocity;
		m_pos = m_pos + m_velocity * t_deltaTime.asSeconds() + 0.5f * m_gravity*(t_deltaTime.asSeconds() * t_deltaTime.asSeconds());
		m_velocity = m_velocity + m_gravity * t_deltaTime.asSeconds();
		m_player.setPosition(m_pos.x, m_pos.y);
	}
	else if (!m_jump && m_pos.y <= 570)
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
