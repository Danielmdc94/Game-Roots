#include "../include/player.h"
#include "../include/engine.h"
#include "../include/obstacle.h"
 
Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initPhysics();
	this->initHitbox();

	// //adds ground to the game
	// ground.pos.x = 0;
	// ground.pos.y = WIN_H - 100;
	// ground.hitbox.rectangle.setFillColor(Color::Green);
	// ground.hitbox.setSize(WIN_W, 100, 0, 0);
	// ground.hitbox.setPosition(ground.pos);
	// //adds the shroom
	// shroom.texture.loadFromFile(SHROOM);
	// shroom.sprite.setTexture(shroom.texture);
	// shroom.hitbox.rectangle.setFillColor(Color::Green);
	// shroom.sprite.setScale(0.5, 0.5);
	// shroom.pos.x = 300;
	// shroom.pos.y = 500;
	// shroom.hitbox.setSize(100, 30, 20, 0);
	// shroom.hitbox.setPosition(shroom.pos);
	// shroom.sprite.setPosition(shroom.pos);
}

void Player::initVariables()
{
	return ;
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
//	position.x = 500.f;
//	position.y = 700.f;
	this->velocityMax = 10.f;
	this->velocityMin = 1.f;
	this->acceleration = 2.f;
	this->drag = 0.9;
	this->gravity = 3.f;
}

void Player::initHitbox()
{
	hitbox.setSize(75, 87, 92, 140);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(sf::Vector2f(x, y));
}

void Player::resetVelocity()
{
	this->velocity.y = 0.f;
}

void	Player::move(const float dirX, const float dirY)
{
	// Acceleration
	this->velocity.x += dirX * this->acceleration;
 	this->velocity.y += dirY * this->acceleration;

	// Limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0) ? -1.f : 1.f);
}

void	Player::updatePhysics()
{
	// Gravity
	this->velocity.y += 1.0f * this->gravity;
	// Limit gravity velocity
	if (std::abs(this->velocity.y) > this->velocityMax)
		this->velocity.y = this->velocityMax * ((this->velocity.y < 0) ? -1.f : 1.f);

	// Deceleration
	this->velocity.x *= this->drag;
	this->velocity.y *= this->drag;

	//Limit deceleration
	if (std::abs(velocity.x) < this->velocityMin)
	 	this->velocity.x = 0.f;
	if (std::abs(velocity.y) < this->velocityMin)
	 	this->velocity.y = 0.f;

	//Move the player sprite
	this->sprite.move(this->velocity);
}

void	Player::updateCollision()
{
	//Moves the hitbox with the sprite
	this->hitbox.setPosition(this->sprite.getPosition());

	// Player collision with screen bounds
	if (hitbox.getPosition().x < 0)
		this->sprite.setPosition(-hitbox.getOffset().x, this->sprite.getPosition().y);
	else if (hitbox.getPosition().x + hitbox.getWidth() > WIN_W)
		this->sprite.setPosition(WIN_W - (hitbox.getWidth() + hitbox.getOffset().x), this->sprite.getPosition().y);
	if (hitbox.getPosition().y < 0)
		this->sprite.setPosition(this->sprite.getPosition().x, -hitbox.getOffset().y);
	else if (hitbox.getPosition().y + hitbox.getHeight() > WIN_H)
		this->sprite.setPosition(this->sprite.getPosition().x, WIN_H - (hitbox.getHeight() + hitbox.getOffset().y));

//	this->sprite.setPosition(ground.groundCheck(this, this->sprite.getPosition()));
//	this->sprite.setPosition(shroom.CollisionCheck(this, this->sprite.getPosition()));
}

// Updates player
void Player::update(double deltaTime)
{
	//Player input
	if (Keyboard::isKeyPressed(Keyboard::A))
		move(-1.f, 0);
	if (Keyboard::isKeyPressed(Keyboard::D))
		move(1.f, 0);
	if (Keyboard::isKeyPressed(Keyboard::S))
		move(0, 1);
	if (Keyboard::isKeyPressed(Keyboard::W))
		move(0, -1);
	updatePhysics();
	updateCollision();
	if (deltaTime)
		return;
}
