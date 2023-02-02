#include "../include/engine.h"

void Engine::input(Event event)
{
    switch (event.type)
    {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == Keyboard::Escape)
                window.close();
            break;
        default:
            break;
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
}