#include "../include/player.h"
#include "../include/engine.h"
 
Player::Player()
{
	// How fast does the player move? In pixels
	speed = 400;
 
	// Associate a texture with the sprite
	texture.loadFromFile(PLAYER_PATH);
	sprite.setTexture(texture);     
	sprite.setScale(0.5, 0.5);

	// Set player's starting position
	position.x = 500;
	position.y = 700;
}
 
// Make the private spite available to the draw() function
Sprite Player::getSprite()
{
	return sprite;
}

void Player::moveLeft()
{
	leftPressed = true;
}
 
void Player::moveRight()
{
	rightPressed = true;
}
 
void Player::stopLeft()
{
	leftPressed = false;
}
 
void Player::stopRight()
{
	rightPressed = false;
}
 
// Move player based on the input this frame,
// the time elapsed, and the speed
void Player::update(float elapsedTime)
{
	// Window bounds collision
	if (sprite.getPosition().x < 0)
		sprite.setPosition(0, sprite.getPosition().y);
	if (sprite.getPosition().x > WIN_W - sprite.getGlobalBounds().width)
		sprite.setPosition(WIN_W - sprite.getGlobalBounds().width, sprite.getPosition().y);
	if (sprite.getPosition().y < 0)
		sprite.setPosition(sprite.getPosition().x, 0);
	if (sprite.getPosition().y > WIN_H - sprite.getGlobalBounds().width)
		sprite.setPosition(sprite.getPosition().x, WIN_H - sprite.getGlobalBounds().width); 
	// Player input
	if (rightPressed)
		sprite.move(speed * elapsedTime, 0.f);
		
	if (leftPressed)
		sprite.move(-speed * elapsedTime, 0.f);
 
	// Now move the sprite to its new position
	//sprite.setPosition(position);   
 
}
