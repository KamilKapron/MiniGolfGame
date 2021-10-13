#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Functional.h"
#include <vector>


class Level : public sf::Drawable {
public:
	Level();
	void load(sf::Drawable &obj);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
	~Level();
private:
	std::vector<sf::Drawable> objects;
};