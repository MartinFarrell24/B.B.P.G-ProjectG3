#pragma once
#include"SFML/Graphics.hpp"
class GamePlay
{
public:
	GamePlay();
	~GamePlay();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow & t_window);
	void loadAssets(sf::Font & t_font);
	void setPickedUpTrue();

private:
	sf::Font m_font;
	sf::Text m_message;
	sf::RectangleShape m_background;
	sf::Texture m_texture;
	bool pickedUp = false;
};