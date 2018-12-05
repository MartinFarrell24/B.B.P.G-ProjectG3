#pragma once
#include"SFML/Graphics.hpp"
#include<math.h> 
class RopeSeg
{
public:
	RopeSeg();
	~RopeSeg();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &t_window);
	void loadAssets();
	sf::RectangleShape getBody();
	void setPos(sf::Vector2f newPos);
	

private:
	sf::RectangleShape m_ropeSeg;
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	sf::Vector2f m_gravity;
	sf::Vector2f m_oldPos;
	int m_mass = 2;
};

