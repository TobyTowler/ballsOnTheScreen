#pragma once

#include "System/Vector2.hpp"
#include <vector>
class Ball {
  private:
    double speed;
    double angle;
    double posx;
    double posy;

  public:
    Ball(double speed, double posx, double posy);

    Ball();

    ~Ball();

    void updatePos();

    sf::Vector2f getPos();
};
