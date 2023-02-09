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

	//Physics variables
	//Vector2f	position;
	Vector2f	velocity;
	double		velocityMaxX;
	double		velocityMaxY;
	double		velocityMin;
	double		acceleration;
	double		jumpAcceleration;
	double		drag;
	double		gravity;
	//Player Hitbox
	Hitbox  	hitbox;
	//Is the player standing on something?
	bool		onGround;
	
	// Initialization
	void		initVariables();
	void		initTexture();
	void		initSprite();
	void		initPhysics();
	void		initHitbox();

	// Public functions
public:

	Obstacle    ground;
	Obstacle    shroom;
	Obstacle	tree;
 
	// Player constructor
	Player();
	
	// Accessors
	Sprite		getSprite() { return this->sprite; }
//	Vector2f	getPosition() { return this->position; }
	Vector2f	getVelocityX() { return this->velocity; }
	Hitbox		getHitbox() { return this->hitbox; }

	// Modifiers
	void		setPosition(const float x, const float y);
	void		resetVelocity();

	// Update functions
	void		move(const float dirX, const float dirY);
	void		jump();
	void		update(double deltaTime);
	void		updatePhysics();
	void		updateCollision();
};

#endif
