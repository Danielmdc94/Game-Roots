#include "../include/engine.h"

void Engine::render()
{
    // Rub out the last frame
    window.clear(Color::Black);

    // Draw the background
    window.draw(backgroundSprite);

	// Render title text
	Text text;
	text.setFont(font);
	text.setString("ROOTS");
	text.setCharacterSize(256);
	text.setFillColor(Color:: Black);
	text.setPosition(window.getSize().x * 0.5 - 128 * 3 +4,
		window.getSize().y * 0.5 - 252);
	window.draw(text);
	text.setFillColor(Color:: Green);
	text.setOutlineColor(Color:: Black);
	text.setPosition(window.getSize().x * 0.5 - 128 * 3,
		window.getSize().y * 0.5 - 256);
	window.draw(text);
	window.draw(player.getSprite());
	text.setPosition(window.getSize().x * 0.5 - 128 * 3,
		window.getSize().y * 0.5 - 256);
	window.draw(text);
	window.draw(player.getSprite());

	// Render resource text
	int water_amount = 20;
	Text water_text;
	std::stringstream ss;
	ss << water_amount;
	water_text.setFont(font);
	water_text.setString(ss.str());
	water_text.setCharacterSize(50);
	water_text.setFillColor(Color:: Black);
	water_text.setPosition(window.getSize().x - 200, 100);
	window.draw(water_text);

    // Show everything we have just drawn
    window.display();
}
