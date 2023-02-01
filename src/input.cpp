#include "../include/engine.h"

void Engine::input()
{
    // Handle the player quitting
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        window.close();
    }

    // Handle the player moving
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        player.moveLeft();
    }
    else
    {
        player.stopLeft();
    }
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        player.moveRight();
    }
    else
    {
        player.stopRight();
    }  

    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        player.moveUp();
    }
    else
    {
        player.stopUp();
    }
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        player.moveDown();
    }
    else
    {
        player.stopDown();
    } 

}