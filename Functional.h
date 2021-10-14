#include "Ball.h"
#include "Background.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace fn {
	//znajduje punkt symetryczny do polozenia myszy wzglêdem srodka pi³ki 
	sf::Vector2f find_symetry(float ballx, float bally, float mousex, float mousey);
	// zmniejsza predkosc overtime 
	//void velocity_decrease(sf::Vector2f& velocity);
	// przelicza wektor odleg³osci pi³ka mysz na predkosc pi³ki
	sf::Vector2f Power(sf::Vector2f& mouse_pos, Ball& ball);

}