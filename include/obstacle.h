#ifndef OBSTACLE_H
# define OBSTACLE_H
# include "hitbox.h"

class Player;

class	Obstacle
{
	private:
	

	public:
	//obstacle specs
    sf::Vector2f pos;
	sf::Sprite sprite;
    sf::Texture texture;
	Hitbox	hitbox;

	sf::Vector2f groundCheck(Player *player, sf::Vector2f position);
	sf::Vector2f CollisionCheck(Player *player, sf::Vector2f position);
 
};
#endif