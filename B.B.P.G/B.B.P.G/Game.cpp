#include "Game.h"
GameState Game::m_currentMode{ GameState::intro };

Game::Game() :
m_window{sf::VideoMode{ 800, 600, 32 }, "Mini-Motivators"},
m_exitGame{ false } //when true game will exit
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
