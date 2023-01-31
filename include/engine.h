#ifndef ENGINE_H
# define ENGINE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "roots.h"
#include "player.h"
 
using namespace sf;
 
class Engine
{
private:

    RenderWindow window;  
 
    Sprite	backgroundSprite;
    Texture	backgroundTexture;
    Font	font;
	Music	music;
	Player	player;

    // Private functions for internal use only
    void input();
    void update(float DeltaTimetInSeconds);
    void render();
 
public:
    // The Engine constructor
    Engine();
 
    // start will call all the private functions
    void start();
};

#endif
