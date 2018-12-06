#include "RopeSegment.h"

RopeSeg::RopeSeg()
{
	m_ropeSeg.setSize(m_size);
	m_ropeSeg.setFillColor(sf::Color::Blue);
}

RopeSeg::~RopeSeg()
{
}


sf::RectangleShape RopeSeg::getBody()
{
	return m_ropeSeg;
}

void RopeSeg::setPos(sf::Vector2f newPos)
{
	m_ropeSeg.setPosition(newPos);
}

void RopeSeg::setAnchor()
{
	m_isAnchor = true;
}

bool RopeSeg::getAnchor()
{
	return m_isAnchor;
}
void RopeSeg::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_ropeSeg);

}

