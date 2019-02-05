#include"Player.h"
#include <iostream>
Player::Player()
{
	if (!m_texture.loadFromFile("ASSETS/_SPRITES/falcon.png"))
	{
		std::cout << "Failed to load player spritesheet!" << std::endl;
		
	}

	m_pos = sf::Vector2f(200, 530);
	m_player.setSize(sf::Vector2f(65, 60));
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

	idleRight.setSpriteSheet(m_texture);
	idleRight.addFrame(sf::IntRect(40, 20, 50, 60));
	idleLeft.setSpriteSheet(m_texture);
	idleLeft.addFrame(sf::IntRect(85, 20, 50, 60));

	jumpRight.setSpriteSheet(m_texture);
	jumpRight.addFrame(sf::IntRect(265, 15, 45, 70));
	jumpLeft.setSpriteSheet(m_texture);
	jumpLeft.addFrame(sf::IntRect(210, 15, 50, 70));

	walkingLeft.setSpriteSheet(m_texture);
	walkingLeft.addFrame(sf::IntRect(385, 50, 65, 60));
	walkingLeft.addFrame(sf::IntRect(308, 50, 65, 60));
	walkingLeft.addFrame(sf::IntRect(676, 50, 65, 60));
	walkingLeft.addFrame(sf::IntRect(595, 50, 65, 60));
	walkingLeft.addFrame(sf::IntRect(518, 50, 50, 60));
	walkingLeft.addFrame(sf::IntRect(465, 50, 50, 60));
	
	animatedSprite = AnimatedSprite(sf::seconds(0.1), true, false);
	animatedSprite.setPosition(m_player.getPosition());
	m_CurrentAnim = &walkingRight;
	m_grapple.setAnchorRope(sf::Vector2f(200, 400));
	
	m_shotgunBullet[0].setVelocityShotgun(sf::Vector2f((1 + (1 / 1.41421356237)), (-(1 / 1.41421356237))));
	m_shotgunBullet[1].setVelocityShotgun(sf::Vector2f(-1, 0));
	m_shotgunBullet[2].setVelocityShotgun(sf::Vector2f((1 + (1 / 1.41421356237)), (1 / 1.41421356237)));

}

Player::~Player()
{
}

void Player::update(sf::Time t_deltaTime)
{
	m_grapple.update(t_deltaTime);
	
	if (m_CurrentAnim == &walkingLeft)
	{
		m_CurrentAnim = &idleLeft;
	}
	if (m_CurrentAnim == &walkingRight)
	{
		m_CurrentAnim = &idleRight;
	}
	
	if (sf::Keyboard::isKeyPressed)
	{
		moveLeft();
		moveRight();
		jump(t_deltaTime);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && poweredUp)
	{
		m_CurrentAnim = &walkingRight;
		m_pos.x -= 300;
		m_player.setPosition(m_pos.x, m_pos.y);
		poweredUp = false;
		reductionOfPowerBar = true;
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
		if (!m_onBlock && poweredUp)
		{
			m_velocity = sf::Vector2f(0, -15);
			poweredUp = false;
			reductionOfPowerBar = true;
		}
		
	}
	
	if (m_jump)
	{
		m_pos += m_velocity;
		m_pos = m_pos + m_velocity * t_deltaTime.asSeconds() + 0.5f * m_gravity*(t_deltaTime.asSeconds() * t_deltaTime.asSeconds());
		m_velocity = m_velocity + m_gravity * t_deltaTime.asSeconds();
		m_player.setPosition(m_pos.x, m_pos.y);
		if (m_CurrentAnim == &walkingRight || m_CurrentAnim == &idleRight)
		{
			m_CurrentAnim = &jumpRight;
		}
		if (m_CurrentAnim == &walkingLeft || m_CurrentAnim == &idleLeft)
		{
			m_CurrentAnim = &jumpLeft;
		}
		
	}
	else if (!m_jump && m_pos.y <= 520)
	{
		m_pos += m_velocity;
		m_pos = m_pos + m_velocity * t_deltaTime.asSeconds() + 0.5f * m_gravity*(t_deltaTime.asSeconds() * t_deltaTime.asSeconds());
		m_velocity = m_velocity + m_gravity * t_deltaTime.asSeconds();
		m_player.setPosition(m_pos.x, m_pos.y);
		if (m_CurrentAnim == &jumpRight)
		{
			m_CurrentAnim = &idleRight;
		}
		if (m_CurrentAnim == &jumpLeft)
		{
			m_CurrentAnim = &idleLeft;
		}
	}
}

void Player::moveRight()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&& !poweredUp)
	{
		m_CurrentAnim = &walkingRight;
		m_pos.x+= 5;
		m_player.setPosition(m_pos.x, m_pos.y);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && poweredUp)
	{
		m_CurrentAnim = &walkingRight;
		m_pos.x += 300;
		m_player.setPosition(m_pos.x, m_pos.y);
		poweredUp = false;
		reductionOfPowerBar = true;
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

void Player::setPoweredUpTrue()
{
	poweredUp = true;
}

void Player::setPoweredUpFalse()
{
	poweredUp = false;
}

bool Player::reducePowerBar()
{
	return reductionOfPowerBar;
}

void Player::stopPowerReduction()
{
	reductionOfPowerBar = false;
}

void Player::setGravityToZero()
{
	m_gravity = sf::Vector2f(0, 0);
}

void Player::setGravity()
{
	m_gravity = sf::Vector2f(0, 9.8f * m_mass);
}
