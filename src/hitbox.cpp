#include "../include/roots.h"
#include <SFML/Graphics.hpp>
#include "../include/hitbox.h"

// Nona was here!

hitbox::hitbox(float size_m2)
{
	box.setFillColor(sf::Color::Green);
	box.setSize(sf::Vector2f(size_m2, size_m2));
}