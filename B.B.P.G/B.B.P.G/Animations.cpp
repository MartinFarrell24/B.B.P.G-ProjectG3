#include "Animations.h"

Animations::Animations() : m_texture(NULL)
{

}

void Animations::addFrame(sf::IntRect rect)
{
	m_frames.push_back(rect);
	
}

void Animations::setSpriteSheet(const sf::Texture& texture)
{
	m_texture = &texture;
}

const sf::Texture* Animations::getSpriteSheet() const
{
	return m_texture;
}

std::size_t Animations::getSize() const
{
	return m_frames.size();
}

const sf::IntRect& Animations::getFrame(std::size_t n) const
{
	return m_frames[n];
}