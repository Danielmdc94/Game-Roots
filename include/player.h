#ifndef PLAYER_H
# define PLAYER_H
#include <SFML/Graphics.hpp>
# include "obstacle.h"
 
using namespace sf;
 
class Player
{
	// All the private variables can only be accessed internally
private:
 
    Vector2f	position;
	Sprite		sprite;
	Texture		texture;
 
	float		speed;
 
	// Public functions
public:
    //Player Hitbox
    Hitbox  hitbox;
    Obstacle    ground;
    Obstacle    shroom;
    // Hitbox  ground;
 
	// Player constructor
	Player();
 
	// Accessors
	Sprite getSprite();
 
	// We will call this function once every frame
	void update(float elapsedTime);
 
};

#endif
