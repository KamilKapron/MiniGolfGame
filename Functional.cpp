#include "functional.h"



sf::Vector2f fn::find_symetry(float ballx, float bally, float mousex, float mousey) {
	return sf::Vector2f(mousex + (2 * (ballx - mousex)), mousey + (2 * (bally - mousey)));
}


void fn::Velocity_decrease(sf::Vector2f& velocity) {
	if (velocity.y < 0) {
		velocity.y += -velocity.y * 0.05;
	}
	if (velocity.y > 0) {
		velocity.y -= velocity.y * 0.05;
	}
	if (velocity.x < 0) {
		velocity.x += -velocity.x * 0.05;
	}
	if (velocity.x > 0) {
		velocity.x -= velocity.x * 0.05;
	}
}

sf::Vector2f fn::Power(sf::Vector2f& mouse_pos, Ball& ball) {
	sf::Vector2f power = fn::find_symetry(ball.getPositionX() + ball.getBall().getRadius(), ball.getPositionY() + ball.getBall().getRadius(), mouse_pos.x, mouse_pos.y);
	power.x -= ball.getPositionX() + ball.getBall().getRadius();
	power.y -= ball.getPositionY() + ball.getBall().getRadius();
	power.x = static_cast<int>(power.x * 0.1);
	power.y = static_cast<int>(power.y * 0.1);
	return power;
}

