#include"PowerBar.h"

PowerBar::PowerBar()
{
	powerBarWidth = 0;
	outerRect.setSize(sf::Vector2f(100, 20));
	outerRect.setFillColor(sf::Color::Red);
	outerRect.setPosition(sf::Vector2f(10, 10));

	innerRect.setSize(sf::Vector2f(powerBarWidth, 10));
	innerRect.setFillColor(sf::Color::Blue);
	innerRect.setPosition(sf::Vector2f(15, 15));

	count = 0;
}

PowerBar::~PowerBar()
{
}

void PowerBar::update(sf::Time t_deltaTime)
{
	count++;
	if (count == 60)
	{
		count = 0;
		if (powerBarWidth < 90)
		{
			powerBarWidth ++;
		}
		
		innerRect.setSize(sf::Vector2f(powerBarWidth, 10));
	}
}

void PowerBar::render(sf::RenderWindow & t_window)
{
	t_window.draw(outerRect);
	t_window.draw(innerRect);
}

int PowerBar::getPowerlevel()
{
	return powerBarWidth;
}

void PowerBar::reducePower()
{
	if (powerBarWidth >= 50)
	{
		powerBarWidth -= 50;
	}
}
