#pragma once
#include"SFML/Graphics.hpp"

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

private:
	sf::RectangleShape m_player;
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	sf::Vector2f m_gravity;
	int m_mass = 2;
	bool m_jump = false;
};
