#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Button : public sf::Drawable {
public:
	Button(sf::Vector2f position, sf::Vector2f size, sf::Font *font, std::string text, sf::Color BasicColor);
	~Button();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update(sf::Vector2f mouse_pos);
	void update_txt(std::string text);

private:
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::RectangleShape shape;
	sf::Font *font;
	sf::Text text;
	sf::Color colorBasic;
	sf::Color colorActive;
};