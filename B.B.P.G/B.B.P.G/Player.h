#pragma once
#include"SFML/Graphics.hpp"
#include "Bullet.h"
#include "AnimatedSprite.h"

class Player
{
public:
	Player();
	~Player();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	void loadAssets();
	void moveLeft();
	void jump(sf::Time t_deltaTime);
	void moveRight();
	sf::RectangleShape getBody();
	void setPos(sf::Vector2f newPos);
	void setJumpFalse();
	void setVelocity();
	void setVelocityToZero();
	void setOnBlockTrue();
	void setOnBlockFalse();

private:
	sf::RectangleShape m_player;
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	sf::Vector2f m_gravity;
	int m_mass = 2;
	bool m_jump = false;
	bool m_onBlock = false;
	bool m_doOnce = false;
	Bullet m_bullet;
	sf::Texture m_texture;
	Animations walkingLeft;
	Animations walkingRight;
	Animations* m_CurrentAnim;
	AnimatedSprite animatedSprite;
};
