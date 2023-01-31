#include "../include/player.h"
 
Player::Player()
{
    // How fast does the player move? In pixels
    speed = 400;
 
    // Associate a texture with the sprite
    texture.loadFromFile("assets/player.jpg");
    sprite.setTexture(texture);     
    
    sprite.setScale(0.5, 0.5);

    // Set player's starting position
    position.x = 500;
    position.y = 600;
 
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
    if (rightPressed)
    {
        position.x += speed * elapsedTime;
    }
 
    if (leftPressed)
    {
        position.x -= speed * elapsedTime;
    }
 
    // Now move the sprite to its new position
    sprite.setPosition(position);   
 
}