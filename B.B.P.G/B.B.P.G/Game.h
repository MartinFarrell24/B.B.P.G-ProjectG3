#pragma once
#include"GameState.h"
#include"Player.h"
#include"Intro.h"
#include"MainMenu.h"
#include"Splash.h"
#include"SFML/Graphics.hpp"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	// used to determin which screen we're on
	static GameState m_currentMode;

	void update();
	void render();
	void loadAssets();
<<<<<<< HEAD
	sf::RectangleShape rectyboy;
	GameState current_state;
=======
>>>>>>> 3d03e0f90ce9d823b1954b49171c3fa33e159a50

private:
	Player m_player;
	MainMenu m_mainMenu;
	Splash m_splash;
	Intro m_intro;
};
