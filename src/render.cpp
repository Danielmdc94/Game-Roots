#include "../include/engine.h"
#include "../include/hitbox.h"

void Engine::render()
{

    // Rub out the last frame
    window.clear(Color::Black);

    // Draw the background
    window.draw(backgroundSprite);

	// Render title text
	Text		text;
	Vector2f	textPos;

	text.setFont(font);
	text.setString("ROOTS");
	text.setCharacterSize(256);
	text.setFillColor(Color:: Green);
	textPos.x = window.getSize().x * 0.5 - 128 * 3 + 4;
	textPos.y = window.getSize().y * 0.5 - 252;
	text.setPosition(textPos.x, textPos.y);
	window.draw(text);
	text.setFillColor(Color(128, 67, 6));
	textPos.x = window.getSize().x * 0.5 - 128 * 3;
	textPos.y = window.getSize().y * 0.5 - 256;
	text.setPosition(textPos.x, textPos.y);
	window.draw(text);
    // window.draw(player.ground.hitbox.box);
    window.draw(player.ground.hitbox.rectangle);
    window.draw(player.shroom.sprite);
    window.draw(player.shroom.hitbox.rectangle);

	//Render player
	window.draw(player.getHitbox().rectangle);
	window.draw(player.getSprite());


	// Render resource text
	int water_amount = 20;
	Text water_text;
	std::stringstream ss;
	ss << water_amount;
	water_text.setFont(font);
	water_text.setString(ss.str());
	water_text.setCharacterSize(50);
	water_text.setFillColor(Color:: Cyan);
	water_text.setPosition(window.getSize().x - 100, 80);
	window.draw(water_text);

    // Show everything we have just drawn
    window.display();
}
