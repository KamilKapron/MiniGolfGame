#include "Background.h"



Background::Background() {
	light_grass.loadFromFile("Textures/Light_Grass.jpg");
	dark_grass.loadFromFile("Textures/Dark_Grass.jpg");
}


void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int W = 0; W * 32 < target.getSize().x; W++) {
		for (int H = 0; H * 32 < target.getSize().y; H++) {
			if ((H + W) % 2 == 0) {
				sf::RectangleShape rectangle(sf::Vector2f(32.f, 32.f));
				rectangle.setTexture(&light_grass);
				rectangle.setPosition(32.f * W, 32.f * H);
				target.draw(rectangle);
			}
			else {
				sf::RectangleShape rectangle(sf::Vector2f(32.f, 32.f));
				rectangle.setTexture(&dark_grass);
				rectangle.setPosition(32.f * W, 32.f * H);
				target.draw(rectangle);
			}
		}
	}
}
Background::~Background() {

}