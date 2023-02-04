#ifndef PLATFORM_H
# define PLATFORM_H
# include "hitbox.h"

class Player;

class	Platform
{
	private:
	

	public:
	//platform hitbox
	Hitbox	hitbox;

	//position of the shroom
    sf::Vector2f pos;
	


	//The platform Sprite
	sf::Sprite sprite;

	// Corresponding texture
    sf::Texture texture;

	sf::Sprite getSpritePlat();

	sf::Vector2f groundCheck(Player *player, sf::Vector2f position);
	sf::Vector2f CollisionCheck(Player *player, sf::Vector2f position);
	// sf::Sprite getSpritePlat();

 
};
#endif