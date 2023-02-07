#include "../include/player.h"
#include "../include/engine.h"
#include "../include/obstacle.h"
 
Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initPhysics();

	//set player hitbox size
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
	shroom.pos.y = 500;
	shroom.hitbox.setSize(100, 30, 20, 0);
	shroom.hitbox.setcoord(shroom.pos);
	shroom.sprite.setPosition(shroom.pos);
}

void Player::initVariables()
{
	position.x = 500;
	position.y = 700;
}

// Load texture from image and give an error if it's not loaded
void Player::initTexture()
{
	if (!this->texture.loadFromFile(PLAYER_PATH))
		std::cout << "ERROR::PLAYER::Could not load player texture!" << "\n";
}

// Associate a texture with the sprite and set the scale
void Player::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(0.5, 0.5);
}

void Player::initPhysics()
{
	position.x = 500.f;
	position.y = 700.f;
	this->velocityMax = 10.f;
	this->velocityMin = 1.f;
	this->acceleration = 2.f;
	this->drag = 0.9;
	this->gravity = 2.f;
	
}

void	Player::move(const float dirX, const float dirY)
{
	// Acceleration
	this->velocity.x += dirX * this->acceleration;
 	this->velocity.y += dirY * this->acceleration;

	// Limit velocity
	if (std::abs(velocity.x) > velocityMax)
		velocity.x = velocityMax * ((velocity.x < 0) ? -1.f : 1.f);
	if (std::abs(velocity.y) > velocityMax)
		velocity.y = velocityMax * ((velocity.y < 0) ? -1.f : 1.f);
}

void	Player::updatePhysics()
{
	// Gravity
	this->velocity.y += 1.0f * this->gravity;

	// Deceleration
	this->velocity.x *= this->drag;
	this->velocity.y *= this->drag;

	//Limit deceleration
	if (std::abs(velocity.x) < velocityMin)
	 	velocity.x = 0.f;
	if (std::abs(velocity.y) < velocityMin)
	 	velocity.y = 0.f;
	
	//Move the player sprite
	this->sprite.move(velocity);
}

// Move player based on the input this frame,
// the time elapsed, and the speed
void Player::update(double deltaTime)
{
	updatePhysics();

	//Player input
	if (Keyboard::isKeyPressed(Keyboard::A))
		move(-1.f, 0);
	if (Keyboard::isKeyPressed(Keyboard::D))
		move(1.f, 0);
	if (Keyboard::isKeyPressed(Keyboard::S))
		move(0, 1);
	if (Keyboard::isKeyPressed(Keyboard::W))
		move(0, -1);
	
	//Collission and trigger checks
	this->sprite.setPosition(ground.groundCheck(this, this->sprite.getPosition()));
	hitbox.setcoord(this->sprite.getPosition());
	this->sprite.setPosition(shroom.CollisionCheck(this, this->sprite.getPosition()));
	if (deltaTime)
		return;
}
