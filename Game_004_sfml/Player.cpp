#include "stdafx.h"
#include "Player.h"

void Player::initVariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
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

void Player::updatePhysics()
{

}

void Player::updateMovement()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->sprite.move(-2.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->sprite.move(2.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //Up
	//{
	//	this->sprite.move(0.f, -1.f);
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //Down
	//{
	//	this->sprite.move(0.f, 1.f);
	//}
}

void Player::updateAnimations()
{
	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asMilliseconds() >= 160.f)
		{
		
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 50.f;
				
			if (this->currentFrame.left >= 200.f)
			this->currentFrame.left = 0;

			
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asMilliseconds() >= 100.f)
		{
			this->currentFrame.top = 37.f;
			this->currentFrame.left += 50.f;

			if (this->currentFrame.left >= 350.f)
				this->currentFrame.left = 50;


			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
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
