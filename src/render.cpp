#include "../include/engine.h"

void Engine::render()
{
    // Rub out the last frame
    Win.clear(Color::Black);

    // Draw the background
    Win.draw(BackgroundSprite);

	// Render title text
	Text text;
	text.setFont(font);
	text.setString("ROOTS");
	text.setCharacterSize(256);
	text.setFillColor(Color:: Black);
	text.setPosition(Win.getSize().x * 0.5 - 128 * 3 +4,
		Win.getSize().y * 0.5 - 252);
	Win.draw(text);
	text.setFillColor(Color:: Green);
	text.setOutlineColor(Color:: Black);
	text.setPosition(Win.getSize().x * 0.5 - 128 * 3,
		Win.getSize().y * 0.5 - 256);
	Win.draw(text);
	Win.draw(player.getSprite());

	// Render resource text
	int water_amount = 20;
	Text water_text;
	std::stringstream ss;
	ss << water_amount;
	water_text.setFont(font);
	water_text.setString(ss.str());
	water_text.setCharacterSize(50);
	water_text.setFillColor(Color:: Black);
	water_text.setPosition(Win.getSize().x - 200, 100);
	Win.draw(water_text);

    // Show everything we have just drawn
    Win.display();
}
