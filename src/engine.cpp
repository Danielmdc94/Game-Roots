#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../include/engine.h"
 
Engine::Engine()
{
    window.create(VideoMode(WIN_W, WIN_H), NAME);
 
    // Load the background into the texture
    // Be sure to scale this image to your screen size
    backgroundTexture.loadFromFile(BACKGROUND_PATH);
 
    // Associate the sprite with the texture
    backgroundSprite.setTexture(backgroundTexture);

    // Load a font to display text
    font.loadFromFile(MAINFONT_PATH);

    // Load a music to play
    music.openFromFile(MAINTHEME_PATH);
    
 
}
 
void Engine::start()
{
    // Timing
    Clock clock;

    music.play();
    while (window.isOpen())
    {
        // Restart the clock and save the elapsed time into DeltaTime
        Time DeltaTime = clock.restart();
 
        // Make a fraction from the delta time
        float DeltaTimeAsSeconds = DeltaTime.asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        input();
        update(DeltaTimeAsSeconds);
        render();
    }
}