#include "Button.h"



Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Font* font, std::string text, sf::Color BasicColor)
	: pos(position), size(size), font(font){

	shape.setPosition(pos);
	shape.setSize(size);
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(18);
	this->text.setOutlineColor(sf::Color::Black);
	this->text.setOutlineThickness(3.f);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);
	this->colorBasic = BasicColor;
	this->colorActive = sf::Color(BasicColor.r + 40, BasicColor.g + 40, BasicColor.b + 40,192);
	shape.setFillColor(BasicColor);
}
Button::~Button() {
}
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(this->shape);
	target.draw(this->text);
}
void Button::update(sf::Vector2f mouse_pos) {
	if (this->shape.getGlobalBounds().contains(mouse_pos)) {
		this->shape.setFillColor(colorActive);
	}
	else {
		this->shape.setFillColor(colorBasic);
	}
}

void Button::update_txt(std::string text) {
	this->text.setString(text);
}