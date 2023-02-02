#ifndef PLAYER_H
# define PLAYER_H
#include <SFML/Graphics.hpp>
# include "../include/hitbox.h"
 
using namespace sf;
 
class Player
{
    // All the private variables can only be accessed internally
private:
 
    // Where is the player
    Vector2f position;
 
    // Sprite for the player
    Sprite sprite;
 
    // Corresponding texture
    Texture texture;

    //hitbox
    // int wdith;
    // int height;
 
    // Which direction(s) is the player currently moving in
    bool leftPressed;
    bool rightPressed;
    bool upPressed;
    bool downPressed;
 
    // Bob's speed in pixels per second
    float speed;
 
    // Public functions
public:
    Hitbox  hitbox;

    // We will set Bob up in the constructor
    Player();
 
    // Send a copy of the sprite to main
    Sprite getSprite();
 
    // Move player in a specific direction
    void moveLeft();
 
    void moveRight();

    void moveUp();
 
    void moveDown();
 
    // Stop player moving in a specific direction
    void stopLeft();
 
    void stopRight();

    void stopUp();
 
    void stopDown();
 
    // We will call this function once every frame
    void update(float elapsedTime);
 
};

#endif
