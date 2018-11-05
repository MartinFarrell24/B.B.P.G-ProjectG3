#include"Level.h"

Level::Level()
{
	m_body.setFillColor(sf::Color::Blue);
}

Level::~Level()
{
}

void Level::update()
{
}

void Level::render(sf::RenderWindow &t_window)
{
	t_window.draw(m_body);
}

void Level::setSize(sf::Vector2f scale)
{
	m_body.setSize(scale);
}

void Level::setPos(sf::Vector2f pos)
{
	m_body.setPosition(pos.x, pos.y);
}

sf::RectangleShape Level::getBody()
{
	return m_body;
}
