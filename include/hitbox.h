#ifndef HITBOX_H
# define HITBOX_H
# include <SFML/Graphics.hpp>

class	Hitbox
{
	private:
	
	//Creates a rectangular object for the entity


	public:
	int	offX;
	int offY;
	sf::Vector2f position;
	sf::RectangleShape box;
	int	width;
	int height;
	Hitbox();
	void setSize(int size_x, int size_y, int offsetX, int offsetY);
	void setcoord(sf::Vector2f position);
	

};

#endif
