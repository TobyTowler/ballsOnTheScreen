#pragma once

#include <vector>
class Block {
    /* origin (x,y)
     * length is right
     * height is down
     */
  public:
    std::vector<float> origin;
    int length;
    int height;
    int health;

    Block(std::vector<float> origin, int length, int height, int health);
    Block();
};
