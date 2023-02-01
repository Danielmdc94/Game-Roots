#include "../include/engine.h"

void render_resource()
{
	int resource_amount = 0;
	Text resource_text;
	std::stringstream ss;
	
	ss << resource_amount;
	resource_text.setFont(font);
	resource_text.setString(ss.str());
	resource_text.setCharacterSize(256);
	resource_text.setFillColor(Color:: Black);

	window.draw(resource_text);
}

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
	//render_resource();

    // Show everything we have just drawn
    Win.display();
}
