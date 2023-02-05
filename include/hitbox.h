#ifndef HITBOX_H
# define HITBOX_H
# include <SFML/Graphics.hpp>

class	Hitbox
{
	private:

	public:
	//offset for the hitboxs, against the aqtual size of the sprite
	int	offX;
	int offY;
	sf::Vector2f position;
	//ectangular act as the the hit box
	sf::RectangleShape box;
	int	width;
	int height;

	//the original setup for hitboxes
	Hitbox();

	//set the size and offset for the hitboxs
	void setSize(int size_x, int size_y, int offsetX, int offsetY);

	//sets the position for the hitbox
	void setcoord(sf::Vector2f position);
	

};

#endif
