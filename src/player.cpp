#include "../include/player.h"
#include "../include/engine.h"
#include "../include/obstacle.h"
 
Player::Player()
{
    // How fast does the player move? In pixels
    speed = 400;
 
    // Associate a texture with the sprite
    texture.loadFromFile(PLAYER_PATH);
    sprite.setTexture(texture);
    sprite.setScale(0.5, 0.5);

	// Set player's starting position, velovity and acceleration
	position.x = 500;
	position.y = 700;
	velocity.x = 0;
	velocity.y = 0;
	acceleration = 1000;
	friction = 0.99;
	gravity = 0.1;
	maxSpeed = 400;

    //set player hitbox
    hitbox.setSize(75, 87, 92, 140);

    //adds ground to the game
    ground.pos.x = 0;
    ground.pos.y = WIN_H - 100;
    ground.hitbox.box.setFillColor(Color::Green);
    ground.hitbox.setSize(WIN_W, 100, 0, 0);
    ground.hitbox.setcoord(ground.pos);
    //adds the shroom
    shroom.texture.loadFromFile(SHROOM);
    shroom.sprite.setTexture(shroom.texture);
    shroom.hitbox.box.setFillColor(Color::Green);
    shroom.sprite.setScale(0.5, 0.5);
    shroom.pos.x = 300;
    shroom.pos.y = 300;
    shroom.hitbox.setSize(100, 30, 20, 0);
    shroom.hitbox.setcoord(shroom.pos);
    shroom.sprite.setPosition(shroom.pos);
}
 


// Make the private spite available to the draw() function
Sprite Player::getSprite()
{
    return sprite;
}
// Move player based on the input this frame,
// the time elapsed, and the speed
void Player::update(double deltaTime)
{
	//Player physics input
	if (Keyboard::isKeyPressed(Keyboard::A))
		applyForce(M_PI, deltaTime);
	if (Keyboard::isKeyPressed(Keyboard::D))
		applyForce(0, deltaTime);
	if (Keyboard::isKeyPressed(Keyboard::S))
		applyForce(M_PI/2, deltaTime);
	if (Keyboard::isKeyPressed(Keyboard::W))
		applyForce(3 *M_PI/2, deltaTime);

	velocity.x *= (1 - friction * deltaTime);
	velocity.y *= (1 - friction * deltaTime);
	position.x += velocity.x * deltaTime;
	position.y += velocity.y * deltaTime;
	sprite.setPosition(position.x, position.y);

	// Window bounds collision
	if (sprite.getPosition().x < 0)
	{
		sprite.setPosition(0, sprite.getPosition().y);
		velocity.y = 0;
	}
		
	if (sprite.getPosition().x > WIN_W - sprite.getGlobalBounds().width)
		sprite.setPosition(WIN_W - sprite.getGlobalBounds().height, sprite.getPosition().y);
	if (sprite.getPosition().y < 0)
		sprite.setPosition(sprite.getPosition().x, 0);
	if (sprite.getPosition().y > WIN_H - sprite.getGlobalBounds().height)
		sprite.setPosition(sprite.getPosition().x, WIN_H - sprite.getGlobalBounds().height); 
    // Window bounds collision
    // if (sprite.getPosition().x < 0)
    //     sprite.setPosition(0, sprite.getPosition().y);
    // if (sprite.getPosition().x > WIN_W - sprite.getGlobalBounds().width)
    //     sprite.setPosition(WIN_W - sprite.getGlobalBounds().height, sprite.getPosition().y);
    // if (sprite.getPosition().y < 0)
    //     sprite.setPosition(sprite.getPosition().x, 0);
    // if (sprite.getPosition().y > WIN_H - sprite.getGlobalBounds().height)
    //     sprite.setPosition(sprite.getPosition().x, WIN_H - sprite.getGlobalBounds().height);
    sprite.setPosition(ground.groundCheck(this, sprite.getPosition()));
    // Player input
    if (Keyboard::isKeyPressed(Keyboard::A))
        sprite.move(-speed * deltaTime, 0.f);
    if (Keyboard::isKeyPressed(Keyboard::D))
        sprite.move(speed * deltaTime, 0.f);
    if (Keyboard::isKeyPressed(Keyboard::S))
        sprite.move(0.f, speed * deltaTime);
    if (Keyboard::isKeyPressed(Keyboard::Space))
        sprite.move(0.f, -speed * deltaTime);
    // Crude gravity implementation
    if (sprite.getPosition().y < 700)
        sprite.move(0, speed / 2 * deltaTime);
    hitbox.setcoord(sprite.getPosition());
    sprite.setPosition(shroom.CollisionCheck(this, sprite.getPosition()));
}

void Player::applyForce(double angle, double deltaTime)
{
	velocity.x += acceleration * cos(angle) * deltaTime;
	velocity.y += acceleration * sin(angle) * deltaTime;
}
