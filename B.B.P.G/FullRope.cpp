#include "FullRope.h"
#include <math.h>
#include<conio.h>
FullRope::FullRope()
{
}

FullRope::~FullRope()
{
}

void FullRope::update(sf::Time t_deltaTime)
{
	for (int i = 0; i < 10; i++)
	{
		if (i < 9)
		{
			connectRope(segments[i],segments[i+1]);
		}
		
	}
	
}



void FullRope::connectRope(RopeSeg t_ropeSegA, RopeSeg t_ropeSegB)
{
	int distBetween = distanceCalc(t_ropeSegA,t_ropeSegB);
	if (distBetween != 0)
	{
		sf::Vector2f vec = vecMultiply((t_ropeSegA.getBody().getPosition()- t_ropeSegB.getBody().getPosition())
			, (100 / distBetween - 1.0));
		if (!t_ropeSegA.getAnchor())
		{
			t_ropeSegA.setPos(vecSubtract(t_ropeSegA.getBody().getPosition(), vecMultiply(vec, 0.5)));
			t_ropeSegB.setPos(vecAdd(t_ropeSegA.getBody().getPosition(), vecMultiply(vec, 0.5)));
		}
		else
		{
			t_ropeSegB.setPos(vecAdd(t_ropeSegA.getBody().getPosition(), vecMultiply(vec, 0.8)));
		}
		
	}
	
}

void FullRope::setAnchorRope(sf::Vector2f m_pos)
{
	segments[0].setPos(m_pos);
	segments[0].setAnchor();
}

float FullRope::distanceCalc(RopeSeg t_ropeSegA, RopeSeg t_ropeSegB)
{
	float xPos = t_ropeSegA.getBody().getPosition().x - t_ropeSegB.getBody().getPosition().x;
	float yPos = t_ropeSegA.getBody().getPosition().y - t_ropeSegB.getBody().getPosition().y;
	float distBetween;

	distBetween = pow(xPos, 2) + pow(yPos, 2);
	distBetween = std::sqrt(distBetween);
	return distBetween;
}

sf::Vector2f FullRope::vecMultiply(sf::Vector2f t_vec1, double t_scaler)
{
	sf::Vector2f totalVec;
	totalVec = sf::Vector2f(t_vec1.x*t_scaler, t_vec1.y*t_scaler);
	return totalVec;
}

sf::Vector2f FullRope::vecSubtract(sf::Vector2f t_vec1, sf::Vector2f t_vec2)
{
	sf::Vector2f totalVec;
	totalVec = sf::Vector2f(t_vec2.x - t_vec1.x, t_vec2.y - t_vec1.y);
	return totalVec;
}

sf::Vector2f FullRope::vecAdd(sf::Vector2f t_vec1, sf::Vector2f t_vec2)
{
	sf::Vector2f totalVec;
	totalVec = sf::Vector2f(t_vec2.x + t_vec1.x, t_vec2.y + t_vec1.y);
	return totalVec;
}
void FullRope::render(sf::RenderWindow & t_window)
{
	
	for (int i = 0; i < 10; i++)
	{
		segments[i].render(t_window);
	}
}