#ifndef HITBOX_H
# define HITBOX_H
# include <SFML/Graphics.hpp>

class	hitbox
{
	private:
	//Creates a rectangular object for the entity
	sf::RectangleShape box;

	public:

	hitbox(float);
};

#endif
