#include "balls.h"
#include "System/Vector2.hpp"
#include <cmath>
#include <iostream>
#include <numbers>

const double time_step = 1.0 / 480.0;

Ball::Ball()
    : speed(20), angle((rand() % 360) * std::numbers::pi_v<double> / 180), posx(400), posy(300) {
    rand();
}

Ball::Ball(double speed, double posx, double posy)
    : speed(speed), angle((rand() % 360) * std::numbers::pi_v<double> / 180), posx(posx),
      posy(posy) {
    rand();
}

Ball::~Ball() {}

void Ball::updatePos() {
    double angle = this->angle;
    double delta_x = speed * std::cos(angle) * time_step;
    double delta_y = speed * std::sin(angle) * time_step;

    this->posx += delta_x;
    this->posy += delta_y;

    // std::cout << "Updated position: posx = " << posx << ", posy = " << posy << std::endl;
};

sf::Vector2f Ball::getPos() { return sf::Vector2f(this->posx, this->posy); }
