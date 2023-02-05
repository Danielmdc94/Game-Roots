#ifndef ENGINE_H
# define ENGINE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include <sstream>
#include "player.h"

# define WIN_NAME "Root"
# define WIN_W 1920
# define WIN_H 1080

# define NAME               "ROOTS"
# define BACKGROUND_PATH    "assets/forest_background.jpg"
# define MAINTHEME_PATH     "assets/forest_music.ogg"
# define MAINFONT_PATH      "assets/tree_font.ttf"
# define PLAYER_PATH        "assets/player_transparent.png"
# define SHROOM             "assets/shroom_head.png"
 
using namespace sf;
 
class Engine
{
private:

	//Window
    RenderWindow	window;
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
