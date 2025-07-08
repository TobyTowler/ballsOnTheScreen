#include "balls.h"
#include "System/Vector2.hpp"
#include <iostream>

const double time_step = 1.0 / 500.0;

Ball::Ball() : velx((rand() % 200) - 100), vely((rand() % 200) - 100), posx(400), posy(300) {}

Ball::Ball(double velx, double vely, double posx, double posy)
    : velx(velx), vely(vely), posx(posx), posy(posy) {}

// Ball::Ball(double velx, double vely) : velx(velx), vely(vely), posx(400), posy(300) {}

Ball::Ball(double posx, double posy)
    : velx((rand() % 200) - 100), vely((rand() % 200) - 100), posx(posx), posy(posy) {}

Ball::~Ball() {}

void Ball::printPos() { std::cout << "BALL POS" << posx << posy << "\n"; }

void Ball::printAngle() {}

void Ball::updatePos(std::vector<Block> &blocks) {

    // screen size
    if (posx < 0 || posx > 790) {
        velx = -velx;
    }
    if (posy < 0 || posy > 590) {
        vely = -vely;
    }

    for (Block &b : blocks) {
        int top = b.originy;
        int bottom = b.originy + b.height;
        int left = b.originx;
        int right = b.originx + b.length;

        if (posx + 10 > left && posx < right && posy > top - 11 && posy < top + 11 ||
            posx + 10 > left && posx < right && posy > bottom - 1 && posy < bottom + 1) {
            b.health--;
            vely = -vely;
        }

        if (posy + 10 > top && posy < bottom && posx > left - 11 && posx < left + 11 ||
            posy + 10 > top && posy < bottom && posx > right - 1 && posx < right + 1) {
            b.health--;
            velx = -velx;
        }
        // Block(std::vector<float> origin, int length, int height, int health);
    }
    posx += velx * time_step;
    posy += vely * time_step;
    // posx += velx;
    // posy += vely;

    // std::cout << "Updated position: posx = " << posx << ", posy = " << posy << std::endl;
};

sf::Vector2f Ball::getPos() { return sf::Vector2f(posx, posy); }
