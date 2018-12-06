#pragma once
#include<SFML/Graphics.hpp>
class PowerBar
{
public:
	PowerBar();
	~PowerBar();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow & t_window);
	int getPowerlevel();
	void reducePower();
private:
	sf::RectangleShape innerRect;
	sf::RectangleShape outerRect;
	int count;
	int powerBarWidth;
};
