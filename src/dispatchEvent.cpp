#include "../include/engine.h"

void Engine::dispatchEvent(Event event)
{
	//Close window when clicking x button
	if (event.type == sf::Event::Closed)
				window.close();
	
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

}