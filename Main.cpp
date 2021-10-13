#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "functional.h"
#include "Button.h"
#include <string>
sf::Clock cloak;
int FPS() {

	float time = cloak.getElapsedTime().asSeconds();
	cloak.restart();
	return static_cast<int>(1 / time);
}
int main()
{
	//////variables///////
	sf::RenderWindow window{ sf::VideoMode{800,640},"Okno",sf::Style::Close};
	window.setFramerateLimit(60);
	sf::Font* font = new sf::Font [1];
	if (font->loadFromFile("Fonts/kongtext.ttf")) {
		std::cout << "Loaded succesfuly" << std::endl;
	}
	//////FPS//////

	Background BG;
	Ball ball(400, 320, 15);
	Button przycisk1(sf::Vector2f(150, 150), sf::Vector2f(400, 200), font, "przycisk1", sf::Color(0, 0, 0, 192));
	Button fps(sf::Vector2f(20, 20), sf::Vector2f(50, 50), font, std::to_string(FPS()), sf::Color(0, 0, 0, 192));
	sf::Vector2f mouse_pos;
	sf::Vector2f power(0, 0);
	sf::Vertex line[2];
	//////window///////
	while (window.isOpen()) {
		sf::Event event;
		int fps_int = FPS();
		mouse_pos.x = sf::Mouse::getPosition(window).x;
		mouse_pos.y = sf::Mouse::getPosition(window).y;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.key.code == sf::Mouse::Left) {
				if (ball.getBall().getGlobalBounds().contains(mouse_pos)) {
					ball.setFlag(true);
				}
			}
		}
		if (ball.getPositionX() < 0) {
			power.x = -power.x;
		}
		if (ball.getPositionX() + 2* ball.getBall().getRadius() > window.getSize().x) {
			power.x = -power.x;
		}
		if (ball.getPositionY() < 0) {
			power.y = -power.y;
		}
		if (ball.getPositionY() + 2 * ball.getBall().getRadius() > window.getSize().y) {
			power.y = -power.y;
		}
		if (event.type == sf::Event::MouseButtonReleased) {
			if (ball.getFlag()) {
				power = fn::Power(mouse_pos, ball);
			}
			ball.setFlag(false);
		}
		
		fn::Velocity_decrease(power);
		ball.getBall().setPosition(ball.getBall().getPosition() + power);
		window.clear();
		window.draw(BG);
		window.draw(przycisk1);
		fps.update_txt(std::to_string(fps_int));
		window.draw(fps);
		window.draw(ball);
		if(ball.getFlag()){
			line[0] = sf::Vertex(sf::Vector2f(ball.getPositionX() + ball.getBall().getRadius(), ball.getPositionY() + ball.getBall().getRadius()),sf::Color::Yellow);
			line[1] = sf::Vertex(fn::find_symetry(ball.getPositionX() + ball.getBall().getRadius(), ball.getPositionY() + ball.getBall().getRadius(), mouse_pos.x, mouse_pos.y), sf::Color::Red);
			window.draw(line, 2, sf::Lines);
		}
		window.display();
		przycisk1.update(mouse_pos);
		fps.update(mouse_pos);
	}
	return 0;
}