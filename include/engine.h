#ifndef ENGINE_H
# define ENGINE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "roots.h"
#include "player.h"
 
using namespace sf;
 
class Engine
{
private:

	void	initVariables();
	void	initWindow();

	//Window
    RenderWindow	window;  
	VideoMode		videoMode;
	Event			event;

	//Variables
    Sprite			backgroundSprite;
    Texture			backgroundTexture;
    Font			font;
	Music			music;
	Player			player;
	Time			deltaTime;
	Clock			clock;

    // Private functions for internal use only
	void input(Event event);
    void update(float DeltaTimetInSeconds);
    void render();
 
public:
    // The Engine constructor and destructor
    Engine();
 
    // start will call all the private functions
    void start();
};

#endif
