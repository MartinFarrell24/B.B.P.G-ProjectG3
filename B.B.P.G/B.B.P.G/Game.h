#pragma once
#include"GameState.h"
#include"Player.h"
#include"Intro.h"
#include"MainMenu.h"
#include"Splash.h"
#include"SFML/Graphics.hpp"
#include<iostream>
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	// used to determin which screen we're on
	static GameState m_currentMode;

	void update(sf::Time t_deltaTime);
	void render();
	void loadAssets();
	void run();
	void processEvents();


private:
	sf::RenderWindow m_window;
	Player m_player;
	MainMenu m_mainMenu;
	Splash m_splash;
	Intro m_intro;
	sf::Font m_textFont;
	bool m_exitGame = false;;
};
