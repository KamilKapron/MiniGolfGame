#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Ball : public sf::Drawable{
public:
	Ball(float x, float y, float r);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool getFlag();
	void setFlag(bool flag);
	sf::CircleShape &getBall();
	void velocityDecrease();
	void update();
	void setVelocity(sf::Vector2f velocity);
	sf::Vector2f &getVelocity();
	
	~Ball();
private:
	sf::Vector2f velocity;
	sf::Texture ball_texture;
	sf::CircleShape shape;
	bool clicked = false;
};