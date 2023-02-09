#include "../include/hitbox.h"
#include <iostream>

Hitbox::Hitbox()
{
	// Color hitbox for debugging
	this->rectangle.setFillColor(sf::Color(0,255,0,100));
	// Initializes the shape
	this->rectangle.setSize(sf::Vector2f(0, 0));
	this->rectangle.setPosition(sf::Vector2f(0, 0));
}

void Hitbox::setPosition(sf::Vector2f position)
{
	position.x += offset.x; 
	position.y += offset.y;
	this->position = position;
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

bool Hitbox::checkCollision(Bound bound, Hitbox hitbox)
{
	if (!this->isTrigger)
	{
		switch (bound)
		{
			case top:
				if (this->position.y < hitbox.getPosition().y + hitbox.getHeight())
					return (1);
				break;
			case bottom:
				if (this->position.y + this->height > hitbox.getPosition().y)
					return (1);
				break;
			case left:
				if (this->position.x < hitbox.getPosition().x + hitbox.getWidth())
					return (1);
			case right:
				if (this->position.x + this->width > hitbox.getPosition().x)
					return (1);
			default:
				break;
		}
	}
	return (0);
}

bool Hitbox::checkTrigger(Hitbox hitbox)
{	
	if (hitbox.isTrigger)
	{
		if ((this->position.y < hitbox.getPosition().y + hitbox.getHeight()
				&& this->position.y + this->height > hitbox.getPosition().y)
				&& (this->position.x < hitbox.getPosition().x + hitbox.getWidth()
				&& this->position.x + this->width > hitbox.getPosition().x))
			return (1);
	}
	return (0);
}