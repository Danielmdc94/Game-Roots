#include "../include/engine.h"
 
Engine::Engine()
{
	window.create(VideoMode(WIN_W, WIN_H), NAME);
	window.setFramerateLimit(144);
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
	// Start playing loaded music track and loop it
	music.play();
	music.setLoop(true);
	// Main game loop
	while (window.isOpen())
	{
		// Restart the clock and save the elapsed time into DeltaTime
		deltaTime = clock.restart();
 
		// Make a fraction from the delta time
		double deltaTimeAsSeconds = deltaTime.asSeconds();

		// Manage events until queue is empty
		while (window.pollEvent(event))
			input(event);

		// Update game state each frame
		update(deltaTimeAsSeconds);

		// Render the current state of the game each frame
		render();
	}
}
