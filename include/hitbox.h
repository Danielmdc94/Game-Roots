#ifndef HITBOX_H
# define HITBOX_H
# include <SFML/Graphics.hpp>

class	Hitbox
{

private:

	int					width;
	int					height;
	sf::Vector2f		position;
	sf::Vector2f		offset;
	sf::RectangleShape	rectangle;

public:
	// Hitbox constructor
	Hitbox();

	bool				isTrigger;
	enum Bound
	{
		top,
		bottom,
		left,
		right
	};

	// Accesors
	sf::Vector2f		getPosition() { return this->position; }
	sf::Vector2f		getOffset() { return this->offset; }
	sf::RectangleShape	getRectangle() { return this->rectangle; }
	int					getWidth() { return this->width; }
	int					getHeight() { return this->height; }

	// Modifiers
	void				setSize(int size_x, int size_y, int offsetX, int offsetY);
	void				setPosition(sf::Vector2f position);

	// Update functions
	bool				checkCollision(Bound bound, Hitbox hitbox);
	bool				checkTrigger(Hitbox hitbox);

};

#endif
