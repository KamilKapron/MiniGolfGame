#include "Ball.h"



Ball::Ball(float x, float y, float r)
{
	if (ball_texture.loadFromFile("Textures/ball_texture.jpg")) {
		this->shape.setTexture(&ball_texture);
	}
	this->velocity = sf::Vector2f(0, 0);
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

sf::CircleShape &Ball::getBall() {
	return this->shape;
}

bool Ball::getFlag() {
	return this->clicked;
}
void Ball::setFlag(bool flag) {
	this->clicked = flag;
}
void Ball::velocityDecrease() {
	if (this->velocity.y < 0) {
		this->velocity.y += -this->velocity.y * 0.05;
	}
	if (this->velocity.y > 0) {
		this->velocity.y -= this->velocity.y * 0.05;
	}
	if (this->velocity.x < 0) {
		this->velocity.x += -this->velocity.x * 0.05;
	}
	if (this->velocity.x > 0) {
		this->velocity.x -= this->velocity.x * 0.05;
	}
}
void Ball::update() {
	this->shape.setPosition(this->shape.getPosition() + this->velocity);
}
void Ball::setVelocity(sf::Vector2f velocity) {
	this->velocity = velocity;
}
sf::Vector2f &Ball::getVelocity() {
	return this->velocity;
}