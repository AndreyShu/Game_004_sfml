#include "stdafx.h"
#include "Player.h"

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
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

void Player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->sprite.move(-1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->sprite.move(1.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //Up
	{
		this->sprite.move(0.f, -1.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //Down
	{
		this->sprite.move(0.f, 1.f);
	}
}

void Player::update()
{
	this->updateMovement();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
