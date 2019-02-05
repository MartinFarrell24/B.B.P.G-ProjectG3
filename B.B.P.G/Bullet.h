#include"SFML/Graphics.hpp"

class Bullet
{
public:
	Bullet();
	~Bullet();

	void update(sf::Vector2f t_pos);
	void render(sf::RenderWindow &t_window);
	void loadAssets();
	void fire(sf::Vector2f t_pos);
	sf::RectangleShape getBody();
	void setPos(sf::Vector2f newPos);
	void setVelocity();
	void setVelocityToZero();
	bool getIsActive();
	void setIsActive(sf::Vector2f t_pos);
	void setVelocityShotgun(sf::Vector2f vel);
	void setShotgunTrue();
	
private:
	sf::RectangleShape m_body;
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	bool isActive = false;
	bool shotgun = false;
	sf::Vector2f shotgunVelocity;
	sf::Texture m_texture;
};
