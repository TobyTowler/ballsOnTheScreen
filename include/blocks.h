#pragma once

#include <vector>
class Block {
    /* origin (x,y)
     * length is right
     * height is down
     */
  public:
    // std::vector<float> origin;
    float originx;
    float originy;
    int length;
    int height;
    int health;

    Block(float originx, float originy, int length, int height, int health);
    Block();
};
