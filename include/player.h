#ifndef PLAYER_H
# define PLAYER_H
#include <SFML/Graphics.hpp>
#include <cmath>
# include "obstacle.h"
 
using namespace sf;
 
class Player
{
	// All the private variables can only be accessed internally
private:

	Sprite		sprite;
	Texture		texture;

	Vector2f	position;
	Vector2f	velocity;
	double		acceleration;
	double		friction;
	double		gravity;
	double		maxSpeed;
	

	double		speed;

	// Public functions
public:
    //Player Hitbox
    Hitbox  	hitbox;
    Obstacle    ground;
    Obstacle    shroom;
    // Hitbox  	ground;
 
	// Player constructor
	Player();
	
	// Accessors
	Sprite		getSprite() { return sprite; }
	double		getPositionX() { return position.x; }
	double		getPositionY() { return position.y; }
	double		getVelocityX() { return velocity.x; }
	double		getVelocityY() { return velocity.y; }
 
	// Public functions
	void		update(double deltaTime);
	void		applyForce(double angle, double deltaTime);

 
};

#endif
