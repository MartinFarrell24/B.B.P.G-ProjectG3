#include"Bullet.h"
#include <iostream>
Bullet::Bullet()
{
	m_pos = sf::Vector2f(200, 580);
	m_body.setSize(sf::Vector2f(5, 5));
	m_body.setFillColor(sf::Color::Green);
	//m_body.setPosition(m_pos.x, m_pos.y);
	
	m_velocity = sf::Vector2f(0, -10);
}

Bullet::~Bullet()
{
}

void Bullet::update( sf::Vector2f t_pos)
{
	
	if (m_body.getPosition().x < 0 ||
		m_body.getPosition().x>800 ||
		m_body.getPosition().y < 0 ||
		m_body.getPosition().y>600)
	{
		isActive = false;
		m_velocity = sf::Vector2f(0, 0);
		
		m_body.setPosition(m_pos);
	}
	if (!isActive)
	{
		m_pos = sf::Vector2f(t_pos);
	}
	
	fire(t_pos);
	
	if (isActive)
	{
		m_pos += m_velocity;
		m_body.setPosition(m_pos);
	}
	
	
}

void Bullet::render(sf::RenderWindow &t_window)
{
	if (isActive)
	{
		t_window.draw(m_body);
	}
	
}

void Bullet::loadAssets()
{
}




void Bullet::fire(sf::Vector2f t_pos)
{
	if (!isActive)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			setIsActive(t_pos);
			m_velocity = sf::Vector2f(0, -2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			setIsActive(t_pos);
			m_velocity = sf::Vector2f(-2, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			setIsActive(t_pos);
			m_velocity = sf::Vector2f(2, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			setIsActive(t_pos);
			m_velocity = sf::Vector2f(0, 2);
		}
	}
}

sf::RectangleShape Bullet::getBody()
{
	return m_body;
}

void Bullet::setPos(sf::Vector2f newPos)
{
	m_pos = newPos;
	m_body.setPosition(m_pos);
}


void Bullet::setVelocity()
{
	m_velocity = sf::Vector2f(0, 2);
}

void Bullet::setVelocityToZero()
{
	m_velocity = sf::Vector2f(0, 0);
}

bool Bullet::getIsActive()
{
	return isActive;
}

void Bullet::setIsActive(sf::Vector2f t_pos)
{
	m_body.setPosition(t_pos);
	isActive = true;
}


