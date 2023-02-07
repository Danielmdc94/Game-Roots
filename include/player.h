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
	double		velocityMax;
	double		velocityMin;
	double		acceleration;
	double		drag;
	double		gravity;
	
		// Initialization
	void		initVariables();
	void		initTexture();
	void		initSprite();
	void		initPhysics();

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
	Sprite		getSprite() { return this->sprite; }
	double		getPositionX() { return this->position.x; }
	double		getPositionY() { return this->position.y; }
	double		getVelocityX() { return this->velocity.x; }
	double		getVelocityY() { return this->velocity.y; }

	// Update functions
	void		move(const float dirX, const float dirY);
	void		update(double deltaTime);
	void		updatePhysics();
};

#endif
