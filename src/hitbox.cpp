#include <SFML/Graphics.hpp>
#include "../include/hitbox.h"

Hitbox::Hitbox()
{
	rectangle.setFillColor(sf::Color(0,255,0,100));
	rectangle.setSize(sf::Vector2f(50, 50));
}

void Hitbox::setPosition(sf::Vector2f position)
{
	position.x += getOffset().x; 
	position.y += getOffset().y;
	Hitbox::position = position;
	rectangle.setPosition(position); 
}

void Hitbox::setSize(int size_x, int size_y, int offsetX, int offsetY)
{
	offset.x = offsetX;
	offset.y = offsetY;
	width = size_x;
	height = size_y;
	rectangle.setSize(sf::Vector2f(size_x, size_y));
}
