#pragma once
#include"SFML/Graphics.hpp"
class Splash
{
public:
	Splash();
	~Splash();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow & t_window);
	void loadAssets(sf::Font & t_font);

private:
	sf::Font m_font;
	sf::Text m_message;
	sf::Text m_message2;
	
	sf::Texture m_texture;
	sf::RectangleShape m_body;
};
