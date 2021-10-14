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
	
	sf::RenderWindow window{ sf::VideoMode{800,640},"Okno",sf::Style::Close};
	window.setFramerateLimit(60);
	//////FONT//////
	sf::Font* font = new sf::Font [1];
	if (font->loadFromFile("Fonts/kongtext.ttf")) {
		std::cout << "Loaded succesfuly" << std::endl;
	}
	//////variables///////
	Background BG;
	Ball ball(400, 320, 15);
	Button new_game(sf::Vector2f(250, 120), sf::Vector2f(300, 100), font, "New Game", sf::Color(0, 0, 0, 192));
	Button level_select(sf::Vector2f(250, 280), sf::Vector2f(300, 100), font, "Level Select", sf::Color(0, 0, 0, 192));
	Button quit(sf::Vector2f(250, 440), sf::Vector2f(300, 100), font, "Quit", sf::Color(0, 0, 0, 192));
	Button fps(sf::Vector2f(0, 0), sf::Vector2f(25, 25), font, std::to_string(FPS()), sf::Color::Transparent);
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
		
		if (event.type == sf::Event::MouseButtonReleased) {
			if (ball.getFlag()) {
				ball.setVelocity(fn::Power(mouse_pos, ball));
			}
			ball.setFlag(false);
		}
		if (ball.getBall().getPosition().x < 0) {
			ball.getVelocity().x = -ball.getVelocity().x;
		}
		if (ball.getBall().getPosition().x + 2 * ball.getBall().getRadius() > window.getSize().x) {
			ball.getVelocity().x = -ball.getVelocity().x;
		}
		if (ball.getBall().getPosition().y < 0) {
			ball.getVelocity().y = -ball.getVelocity().y;
		}
		if (ball.getBall().getPosition().y + 2 * ball.getBall().getRadius() > window.getSize().y) {
			ball.getVelocity().y = -ball.getVelocity().y;
		}
		ball.velocityDecrease();
		ball.update();
		//////Displaying///////
		window.clear();
		window.draw(BG);
		window.draw(new_game);
		window.draw(level_select);
		window.draw(quit);
		fps.update_txt(std::to_string(fps_int));
		window.draw(fps);
		window.draw(ball);
		if(ball.getFlag()){
			line[0] = sf::Vertex(sf::Vector2f(ball.getBall().getPosition().x + ball.getBall().getRadius(), ball.getBall().getPosition().y + ball.getBall().getRadius()), sf::Color::Yellow);
			line[1] = sf::Vertex(fn::find_symetry(ball.getBall().getPosition().x + ball.getBall().getRadius(), ball.getBall().getPosition().y + ball.getBall().getRadius(), mouse_pos.x, mouse_pos.y), sf::Color::Red);
			window.draw(line, 2, sf::Lines);
		}
		window.display();
		new_game.update(mouse_pos);
		level_select.update(mouse_pos);
		quit.update(mouse_pos);
	}
	return 0;
}