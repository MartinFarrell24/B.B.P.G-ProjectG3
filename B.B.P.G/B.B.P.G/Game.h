#pragma once
#include"GameState.h"
#include"Player.h"
#include"Intro.h"
#include"MainMenu.h"
#include"Splash.h"
//#include"SFML/Graphics.hpp"

class Game
{
public:
	Game();
	~Game();

	void update();
	void render();
	void loadAssets();
	sf::RectangleShape rectyboy;

private:
	Player m_player;
	MainMenu m_mainMenu;
	Splash m_splash;
	Intro m_intro;
};
