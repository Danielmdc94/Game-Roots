#ifndef HITBOX_H
# define HITBOX_H
# include <SFML/Graphics.hpp>

class	Hitbox
{

private:

	int	width;
	int height;
	sf::Vector2f position;
	sf::Vector2f offset;

public:

	//Hitbox constructor
	Hitbox();

	sf::RectangleShape rectangle;
	

	sf::Vector2f	getPosition() { return this->position; }
	sf::Vector2f	getOffset() { return this->offset; }

	int				getWidth() { return this->width; }
	int				getHeight() { return this->height; }

	//set the size and offset for the hitbox
	void setSize(int size_x, int size_y, int offsetX, int offsetY);

	//sets the position for the hitbox
	void setPosition(sf::Vector2f position);
	

};

#endif
