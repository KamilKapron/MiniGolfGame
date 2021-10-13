#include "Ball.h"



Ball::Ball(float x, float y, float r)
{
	if (ball_texture.loadFromFile("Textures/ball_texture.jpg")) {
		this->shape.setTexture(&ball_texture);
	}
	this->shape.setRadius(r);
	this->shape.setFillColor(sf::Color(255, 255, 255));
	this->shape.setOutlineThickness(1.f);
	this->shape.setOutlineColor(sf::Color(0, 0, 0));
	this->shape.setPosition(x, y);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	target.draw(this->shape);
}

Ball::~Ball() {

}
float Ball::getPositionX() const {
	return this->shape.getPosition().x;
}
float Ball::getPositionY() const {
	return this->shape.getPosition().y;
}
sf::CircleShape &Ball::getBall() {
	return this->shape;
}

bool Ball::getFlag() {
	return clicked;
}
void Ball::setFlag(bool flag) {
	clicked = flag;
}