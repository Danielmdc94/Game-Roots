#include "../include/roots.h"
#include "../include/player.h"
 
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

    // sets the hitbox for the player
    box.x = 100;
    box.y = 100;
    // wdith = 50.0f;
    // height = 50.0f;
    // hitbox(500.f);
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


void Player::moveUp()
{
    upPressed = true;
}
 
void Player::moveDown()
{
    downPressed = true;
}
 
void Player::stopUp()
{
    upPressed = false;
}
 
void Player::stopDown()
{
    downPressed = false;
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
 
    if (upPressed)
    {
        position.y -= speed * elapsedTime;
    }
 
    if (downPressed)
    {
        position.y += speed * elapsedTime;
    }
    //
    // hitbox
    //Screen Collision checker
    if (position.x < 0)
        position.x = 0;
    else if (position.x + box.x > WIN_W)
        position.x = WIN_W - box.x;
    if (position.y < 0)
        position.y = 0;
    else if (position.y + box.y > WIN_H)
        position.y = WIN_H - box.y;

    // Now move the sprite to its new position
    sprite.setPosition(position);   
 
}
