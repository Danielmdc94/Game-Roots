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

// Move player based on the input this frame,
// the time elapsed, and the speed
void Player::update(float elapsedTime)
{
	// Window bounds collision
	if (sprite.getPosition().x < 0)
		sprite.setPosition(0, sprite.getPosition().y);
	if (sprite.getPosition().x > WIN_W - sprite.getGlobalBounds().width)
		sprite.setPosition(WIN_W - sprite.getGlobalBounds().height, sprite.getPosition().y);
	if (sprite.getPosition().y < 0)
		sprite.setPosition(sprite.getPosition().x, 0);
	if (sprite.getPosition().y > WIN_H - sprite.getGlobalBounds().height)
		sprite.setPosition(sprite.getPosition().x, WIN_H - sprite.getGlobalBounds().height); 
	// Player input
	if (Keyboard::isKeyPressed(Keyboard::A))
		sprite.move(-speed * elapsedTime, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::D))
		sprite.move(speed * elapsedTime, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::S))
		sprite.move(0.f, speed * elapsedTime);
	if (Keyboard::isKeyPressed(Keyboard::Space))
		sprite.move(0.f, -speed * elapsedTime);
	// Crude gravity implementation
	if (sprite.getPosition().y < 700)
    	sprite.move(0, speed / 2 * elapsedTime);

}
