#ifndef PLAYER_H
# define PLAYER_H
#include <SFML/Graphics.hpp>
 
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
 
	// Player constructor
	Player();
 
	// Accessors
	Sprite getSprite();
 
	// We will call this function once every frame
	void update(float elapsedTime);
 
};

#endif
