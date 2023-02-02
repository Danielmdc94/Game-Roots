#include "../include/engine.h"
#include "../include/hitbox.h"

void Engine::render()
{

	// RectangleShape box;
    // box.setFillColor(Color::Green);
	// box.setSize(sf::Vector2f(50.f, 50.f));

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
	
	// if(player.getSprite().getGlobalBounds().intersects(box.getGlobalBounds()))
    // {
    //     box.setFillColor(Color::Red);
    // }
    // else
    //     box.setFillColor(Color::Green);
	window.draw(text);
    // window.draw(box);
	window.draw(player.getSprite());
	window.draw(player.hitbox.box);

    // Show everything we have just drawn
    window.display();
}
