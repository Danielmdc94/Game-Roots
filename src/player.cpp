#include "../include/engine.h"
# include "../include/platform.h"




 
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

    //adds ground to the game
    ground.pos.x = 0;
    ground.pos.y = WIN_H - 100;
    ground.hitbox.box.setFillColor(Color::Green);
	ground.hitbox.setSize(WIN_W, 100, 0, 0);
    ground.hitbox.setcoord(ground.pos);
    //adds the shroom
    shroom.texture.loadFromFile(SHROOM);
    shroom.sprite.setTexture(shroom.texture); 
    shroom.hitbox.box.setFillColor(Color::Green);
    shroom.sprite.setScale(0.5, 0.5);
    shroom.pos.x = 100;
	shroom.pos.y = 100;
	shroom.hitbox.setSize(100, 30, 20, 20);
    shroom.hitbox.setcoord(shroom.pos);
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
    //set the cords for the hitbox rlative to the player
    hitbox.setcoord(position);
    
    //Screen and ground Collision checker
    if (hitbox.position.x < 0)
        position.x = -hitbox.offX;
    else if (position.x + hitbox.width + hitbox.offX > WIN_W)
        position.x = WIN_W - (hitbox.width + hitbox.offX);
    if (hitbox.position.y < 0)
        position.y = -hitbox.offY;
    else if (position.y + hitbox.height + hitbox.offY > WIN_H - ground.hitbox.height)
        position.y = WIN_H - (hitbox.height + hitbox.offY + ground.hitbox.height);
    
    //Check if player collieded with any otehr obstacle


    // Now move the sprite to its new position
    sprite.setPosition(position);   
 
}
