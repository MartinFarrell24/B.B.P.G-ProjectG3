#pragma once
#include"Player.h"
#include"Intro.h"
#include"MainMenu.h"
#include"Splash.h"
class Game
{
	Game();
	~Game();

	void update();
	void render();
	void loadAssets();

private:
	Player m_player;
	MainMenu m_mainMenu;
	Splash m_splash;
	Intro m_intro;
};
