#include "../include/engine.h"

 
Player::Player()
{
    // How fast does the player move? In pixels
    speed = 800;
 
    // Associate a texture with the sprite
    texture.loadFromFile(PLAYER_PATH);
    sprite.setTexture(texture);     
    sprite.setScale(0.5, 0.5);

    // Set player's starting position
    position.x = 500;
    position.y = 700;

    // sets the hitbox for the player
    hitbox.setSize(75, 87, 5, 115);
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
    hitbox.setcoord(position);
    Player::getSprite();
    // hitbox
    //Screen Collision checker
    if (hitbox.position.x < 0)
        position.x = -hitbox.offX;
    else if (position.x + hitbox.width + hitbox.offX > WIN_W)
        position.x = WIN_W - (hitbox.width + hitbox.offX);
    if (hitbox.position.y < 0)
        position.y = -hitbox.offY;
    else if (position.y + hitbox.height + hitbox.offY > WIN_H - Engine::getGround().box.height)
        position.y = WIN_H - (hitbox.height + hitbox.offY + Engine::getGround().box.height);


    // Now move the sprite to its new position
    sprite.setPosition(position);   
 
}
