#pragma once
#include"GameState.h"
#include"Player.h"
#include"Intro.h"
#include"MainMenu.h"
#include"Splash.h"
#include "GamePlay.h"
#include"Level.h"
#include"PowerBar.h"
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
	sf::RectangleShape rectyboy;
	void run();
	void processEvents();


private:
	sf::RenderWindow m_window;
	Player m_player;
	MainMenu m_mainMenu;
	GamePlay m_gamePlay;
	Splash m_splash;
	Intro m_intro;
	PowerBar m_powerBar;

	sf::Font m_textFont;
	bool m_exitGame = false;
	bool pickedUp = false;
	Level m_block[5];
	sf::Texture m_texture;
	sf::Texture m_texture2;
	sf::RectangleShape m_background;
	sf::RectangleShape m_shotgun;
	sf::RectangleShape m_pauseButtons[2];
	int buttonHighlighted = 0;
	bool buttonPressed = false;
	bool gamePaused = false;
	int buttonTimer = 0;
	int mainMenuTimer = 0;
	sf::Text pausedButtonText[2];
};
