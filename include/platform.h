#ifndef PLATFORM_H
# define PLATFORM_H
# include "hitbox.h"


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

	// void groundScreenCheck(Player *player);
	// sf::Sprite getSpritePlat();

 
};
#endif