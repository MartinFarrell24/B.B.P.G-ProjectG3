#pragma once
#include"SFML/Graphics.hpp"

class Slime
{
public:
	Slime();
	~Slime();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
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
	void turnToPlayer(sf::Vector2f t_playerPos);
private:
	sf::RectangleShape m_slime;
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	sf::Vector2f m_gravity;
	int m_mass = 2;
	bool m_jump = false;
	bool m_onBlock = false;
	bool m_doOnce = false;
	
	int m_jumpCounter = 200;
	sf::Texture m_texture;
	
};
