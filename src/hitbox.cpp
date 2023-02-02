#include "../include/roots.h"
#include <SFML/Graphics.hpp>
#include "../include/hitbox.h"


void Hitbox::setcoord(sf::Vector2f position)
{
	position.x += offX; 
	position.y += offY;
	Hitbox::position = position;
	box.setPosition(position); 
}


void Hitbox::setSize(int size_x, int size_y, int offsetX, int offsetY)
{
	offX = offsetX;
	offY = offsetY;
	width = size_x;
	height = size_y;
	box.setSize(sf::Vector2f(size_x, size_y));
}

Hitbox::Hitbox()
{
	box.setFillColor(sf::Color(0,255,0,100));
	box.setSize(sf::Vector2f(50, 50));
}