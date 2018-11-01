#pragma once
#include"SFML/Graphics.hpp"

class Player
{
public:
	Player();
	~Player();

	void update();
	void render();
	void loadAssets();
	void moveLeft();
	void jump();
	void moveRight();

private:
};
