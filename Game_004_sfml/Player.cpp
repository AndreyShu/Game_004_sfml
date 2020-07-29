#include "stdafx.h"
#include "Player.h"

void Player::initVariables()
{
	this->moving = false;
}

void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("Textures/adventurer-v1.5-Sheet.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the player sprite sheet!" << "\n";
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 50, 37);

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(3.5f, 3.5f);
}

void Player::initAnimations()
{
	this->animationTimer.restart();
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

Player::~Player()
{

}

void Player::updateMovement()
{
	this->moving = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->sprite.move(-1.f, 0.f);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->sprite.move(1.f, 0.f);
		this->moving = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //Up
	{
		this->sprite.move(0.f, -1.f);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //Down
	{
		this->sprite.move(0.f, 1.f);
		this->moving = true;
	}
}

void Player::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asMilliseconds() >= 160.f)
	{
		if (this->moving == false) //IDLE animation
		{
		this->currentFrame.left += 50.f;

		if (this->currentFrame.left >= 200.f)
			this->currentFrame.left = 0;
		}

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
