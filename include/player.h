#ifndef PLAYER_H
# define PLAYER_H
#include <SFML/Graphics.hpp>
 
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
 
    // Which direction(s) is the player currently moving in
    bool leftPressed;
    bool rightPressed;
 
    // Bob's speed in pixels per second
    float speed;
 
    // Public functions
public:
 
    // We will set Bob up in the constructor
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
