#include "Game.h"
GameState Game::m_currentMode{ GameState::intro };

Game::Game() :
<<<<<<< HEAD
m_window{sf::VideoMode{ 800, 600, 32 }, "Mini-Motivators"},
m_exitGame{ false } //when true game will exit
>>>>>>> 3d03e0f90ce9d823b1954b49171c3fa33e159a50
{
}

Game::~Game()
{
}

void Game::update()
{
}

void Game::render()
{
}

void Game::loadAssets()
{
}
