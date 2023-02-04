#include "../include/engine.h"
#include "../include/hitbox.h"

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
	
	// if(player.hitbox.box.getGlobalBounds().intersects(ground.box.getGlobalBounds()))
    // {
    //     ground.box.setFillColor(Color::Red);
    // }
    // else
    //     ground.box.setFillColor(Color::Green);
	window.draw(text);
    // window.draw(player.ground.hitbox.box);
    window.draw(player.ground.hitbox.box);
    window.draw(player.shroom.sprite);
    window.draw(player.shroom.hitbox.box);
	window.draw(player.getSprite());
	window.draw(player.hitbox.box);

    // Show everything we have just drawn
    window.display();
}
