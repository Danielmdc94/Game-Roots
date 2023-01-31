#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../include/engine.h"
 
Engine::Engine()
{
	window.create(VideoMode(WIN_W, WIN_H), NAME);
 
	// Load the background into the texture
	// Be sure to scale this image to your screen size
	backgroundTexture.loadFromFile(BACKGROUND_PATH);
 
	// Associate the sprite with the texture
	backgroundSprite.setTexture(backgroundTexture);

	// Load a font to display text
	font.loadFromFile(MAINFONT_PATH);

	// Load a music to play
	music.openFromFile(MAINTHEME_PATH);
	
 
}
 
void Engine::start()
{
	// Timing
	Clock clock;

	music.play();
	while (window.isOpen())
	{
		// Restart the clock and save the elapsed time into DeltaTime
		deltaTime = clock.restart();
 
		// Make a fraction from the delta time
		float deltaTimeAsSeconds = deltaTime.asSeconds();
		while (window.pollEvent(event))
			dispatchEvent(event);
		update(deltaTimeAsSeconds);
		render();
	}
}