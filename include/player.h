#ifndef PLAYER_H
# define PLAYER_H
#include <SFML/Graphics.hpp>
 
using namespace sf;
 
class Player
{
	// All the private variables can only be accessed internally
private:

	Vector2f position;
	Sprite sprite;
	Texture texture;
 
	bool leftPressed;
	bool rightPressed;
//	bool spacePressed;
 
	float speed;
 
	// Public functions
public:
 
	// Player constructor
	Player();
 
	// Send a copy of the sprite to main
	Sprite getSprite();
 
	// Move player in a specific direction
	void moveLeft();
	void moveRight();
 
	// Stop player moving in a specific direction
	void stopLeft();
	void stopRight();
 
	// We will call this function once every frame
	void update(float elapsedTime);
 
};

#endif
