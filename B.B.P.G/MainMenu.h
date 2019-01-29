#pragma once
#include"SFML/Graphics.hpp"
#include"GameState.h"
class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow & t_window);
	void loadAssets(sf::Font & t_font);

private:
	sf::Font m_font;
	sf::Text m_message[3];
	int buttonHighlighted = 0;
	sf::RectangleShape m_buttons[3];
	bool pressedOnce = false;
	int count = 0;
};
