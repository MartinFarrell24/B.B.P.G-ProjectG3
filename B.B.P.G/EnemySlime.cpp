#include"EnemySlime.h"
#include "AnimatedSprite.h"
#include <iostream>
Animations idleRight;
Animations idleLeft;
Animations jumpRight;
Animations jumpLeft;
Animations* m_CurrentAnimSlime;
AnimatedSprite animatedSprite;
Slime::Slime()
{
	if (!m_texture.loadFromFile("ASSETS/_SPRITES/slimeyboy.png"))
	{
		std::cout << "Failed to load player spritesheet!" << std::endl;

	}
	//633,313
	m_pos = sf::Vector2f(200, 530);
	m_slime.setSize(sf::Vector2f(20, 30));
	m_slime.setFillColor(sf::Color::Red);
	m_slime.setPosition(m_pos.x, m_pos.y);
	m_gravity = sf::Vector2f(0, 9.8f * m_mass);
	m_velocity = sf::Vector2f(0, -10);


	idleRight.setSpriteSheet(m_texture);
	idleRight.addFrame(sf::IntRect(0, 0, 60, 30));
	idleLeft.setSpriteSheet(m_texture);
	idleLeft.addFrame(sf::IntRect(0, 30, 60, 30));

	jumpRight.setSpriteSheet(m_texture);
	jumpRight.addFrame(sf::IntRect(265, 15, 45, 70));
	jumpLeft.setSpriteSheet(m_texture);
	jumpLeft.addFrame(sf::IntRect(210, 15, 50, 70));

	animatedSprite = AnimatedSprite(sf::seconds(0.1), true, false);
	animatedSprite.setPosition(m_slime.getPosition());
	m_CurrentAnimSlime = &idleRight;
	m_jumpCounter = 100;

}

Slime::~Slime()
{
}

void Slime::update(sf::Time t_deltaTime)
{
	

	if (m_CurrentAnimSlime == &jumpLeft)
	{
		m_CurrentAnimSlime = &idleLeft;
		moveLeft();
	}
	if (m_CurrentAnimSlime == &jumpRight)
	{
		m_CurrentAnimSlime = &idleRight;
		moveRight();
	}
	
		
		
		jump(t_deltaTime);
		
	



	

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
	animatedSprite.setPosition(m_slime.getPosition());
	animatedSprite.update(t_deltaTime);
	animatedSprite.play(*m_CurrentAnimSlime);
	animatedSprite.setLooped(true);
	
}

void Slime::render(sf::RenderWindow &t_window)
{
	t_window.draw(animatedSprite);
}



void Slime::moveLeft()
{
	
		//m_CurrentAnimSlime = &jumpLeft;
		m_pos.x += 0.2;
		m_slime.setPosition(m_pos.x, m_pos.y);
	
}

void Slime::jump(sf::Time t_deltaTime)
{
	
	if (m_CurrentAnimSlime != &idleLeft || m_CurrentAnimSlime != &idleRight)
	{
		m_jump = true;
		if (m_velocity != sf::Vector2f(0, -10) && m_onBlock)
		{
			m_velocity = sf::Vector2f(0, -10);
			m_onBlock = false;
		}



		if (m_jump)
		{
			m_pos += m_velocity;
			m_pos = m_pos + m_velocity * t_deltaTime.asSeconds() + 0.5f * m_gravity*(t_deltaTime.asSeconds() * t_deltaTime.asSeconds());
			m_velocity = m_velocity + m_gravity * t_deltaTime.asSeconds();
			m_slime.setPosition(m_pos.x, m_pos.y);
			if (m_CurrentAnimSlime == &idleRight)
			{
				m_CurrentAnimSlime = &jumpRight;
			}
			if (m_CurrentAnimSlime == &idleLeft)
			{
				m_CurrentAnimSlime = &jumpLeft;
			}
			m_jumpCounter--;
			if (m_jumpCounter <= 500)
			{
				if (m_CurrentAnimSlime == &jumpRight)
				{
					m_CurrentAnimSlime = &idleRight;
				}
				if (m_CurrentAnimSlime == &jumpLeft)
				{
					m_CurrentAnimSlime = &idleLeft;
				}
				if (m_jumpCounter <= 0)
				{
					//m_jumpCounter = 1000;
				}
			}
		}
		else if (!m_jump && m_pos.y <= 520)
		{
			m_pos += m_velocity;
			m_pos = m_pos + m_velocity * t_deltaTime.asSeconds() + 0.5f * m_gravity*(t_deltaTime.asSeconds() * t_deltaTime.asSeconds());
			m_velocity = m_velocity + m_gravity * t_deltaTime.asSeconds();
			m_slime.setPosition(m_pos.x, m_pos.y);
			if (m_CurrentAnimSlime == &jumpRight)
			{
				m_CurrentAnimSlime = &idleRight;
			}
			if (m_CurrentAnimSlime == &jumpLeft)
			{
				m_CurrentAnimSlime = &idleLeft;
			}
		}
	}
}

void Slime::moveRight()
{
	
		//m_CurrentAnimSlime = &jumpRight;
		m_pos.x -= 0.2;
		m_slime.setPosition(m_pos.x, m_pos.y);
	
	
}

sf::RectangleShape Slime::getBody()
{
	return m_slime;
}

void Slime::setPos(sf::Vector2f newPos)
{
	m_pos = newPos;
	m_slime.setPosition(m_pos);
}

void Slime::setJumpFalse()
{
	m_jump = false;
}

void Slime::setVelocity()
{
	m_velocity = sf::Vector2f(0, 2);
}

void Slime::setVelocityToZero()
{
	m_velocity = sf::Vector2f(0, 0);
}

void Slime::setOnBlockTrue()
{
	m_onBlock = true;
}

void Slime::setOnBlockFalse()
{
	m_onBlock = false;
}

void Slime::turnToPlayer(sf::Vector2f t_playerPos)
{
	if (m_pos.x <= t_playerPos.x && m_CurrentAnimSlime != &jumpRight && m_CurrentAnimSlime != &jumpLeft)
	{
		m_CurrentAnimSlime = &idleRight;
		m_velocity.x = 2;
	}
	if (m_pos.x > t_playerPos.x && m_CurrentAnimSlime != &jumpRight && m_CurrentAnimSlime != &jumpLeft)
	{
		m_CurrentAnimSlime = &idleLeft;
		m_velocity.x = -2;
	}
}


