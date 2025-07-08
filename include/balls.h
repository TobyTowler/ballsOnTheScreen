#pragma once

#include "System/Vector2.hpp"
#include "blocks.h"

class Ball {
  private:
    double velx;
    double vely;
    double posx;
    double posy;

  public:
    Ball(double velx, double vely, double posx, double posy);

    Ball(double velx, double vely);

    Ball();

    ~Ball();

    sf::Vector2f getPos();

    void printPos();

    void printAngle();

    void updatePos(std::vector<Block> &blocks);
};
