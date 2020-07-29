#pragma once

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;

	void initTexture();
	void initSprite();

	//Animation
	sf::IntRect currentFrame;

	//Movement

	//Core values

public:

	Player();
	virtual ~Player();

	//Functions
	void updateMovement();
	void update();
	void render(sf::RenderTarget& target);

};

