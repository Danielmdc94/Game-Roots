#ifndef ENGINE_H
# define ENGINE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "roots.h"
 
using namespace sf;
 
class Engine
{
private:

    RenderWindow Win;  
 
    Sprite	BackgroundSprite;
    Texture	BackgroundTexture;
    Font	font;
	Music	music;

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
