#pragma once
#include"SFML/Graphics.hpp"
class Level
{
public:
	Level();
	~Level();
	void update();
	void render(sf::RenderWindow &t_window);
	void setSize(sf::Vector2f scale);
	void setPos(sf::Vector2f pos);
	sf::RectangleShape getBody();

private:
	sf::Texture m_texture;
	sf::RectangleShape m_body;
};