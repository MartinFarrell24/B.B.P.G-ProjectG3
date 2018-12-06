#pragma once
#include "RopeSegment.h"

class FullRope
{
public:
	FullRope();
	~FullRope();
	
	void update(sf::Time t_deltaTime);
	void connectRope(RopeSeg t_ropeSegA, RopeSeg t_ropeSegB);
	void setAnchorRope(sf::Vector2f m_pos);
	float distanceCalc(RopeSeg t_ropeSegA, RopeSeg t_ropeSegB);
	sf::Vector2f vecMultiply(sf::Vector2f t_vec1, double t_scaler);
	sf::Vector2f vecSubtract(sf::Vector2f t_vec1, sf::Vector2f t_vec2);
	sf::Vector2f vecAdd(sf::Vector2f t_vec1, sf::Vector2f t_vec2);
	void render(sf::RenderWindow & t_window);

private:
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	sf::Vector2f m_gravity;
	sf::Vector2f m_oldPos;
	int m_mass = 2;
	RopeSeg segments[10];
};