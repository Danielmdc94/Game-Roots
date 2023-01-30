#include "../include/engine.h"

void Engine::render()
{
    // Rub out the last frame
    Win.clear(Color::Black);

    // Draw the background
    Win.draw(BackgroundSprite);

	// Render title text
	sf::Text text("ROOTS", font, 240);

    // Show everything we have just drawn
    Win.display();
}