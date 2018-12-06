#pragma once
#include"SFML/Graphics.hpp"
#include<math.h> 
class RopeSeg
{
public:
	RopeSeg();
	~RopeSeg();

	void update(sf::Time t_deltaTime);
	void loadAssets();
	sf::RectangleShape getBody();
	void setPos(sf::Vector2f newPos);
	void setAnchor();
	bool getAnchor();
	void render(sf::RenderWindow & t_window);

private:
	sf::RectangleShape m_ropeSeg;
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	sf::Vector2f m_gravity;
	sf::Vector2f m_oldPos;
	sf::Vector2f m_size=sf::Vector2f(10,40);
	bool m_isAnchor = false;
	int m_mass = 2;
};

