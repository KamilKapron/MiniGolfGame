#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Ball : public sf::Drawable{
public:
	Ball(float x, float y, float r);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float getPositionX() const;
	float getPositionY() const;
	bool getFlag();
	void setFlag(bool flag);
	sf::CircleShape &getBall();

	
	~Ball();
private:
	sf::Texture ball_texture;
	sf::CircleShape shape;
	bool clicked = false;
};