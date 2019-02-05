#pragma once
#include"SFML/Graphics.hpp"
//#include "AnimatedSprite.h"
class GamePlay
{
public:
	GamePlay();
	~GamePlay();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow & t_window,bool t_levelTwo);
	void loadAssets(sf::Font & t_font);
	void setPickedUpTrue();

private:
	sf::Font m_font;
	sf::Text m_message;
	sf::RectangleShape m_background;
	sf::RectangleShape m_regBackground;
	
	sf::Texture m_texture;
	sf::Texture m_facTex;
	bool pickedUp = false;
};