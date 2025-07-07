#pragma once

#include <vector>
class Block {
    /* origin (x,y)
     * length is right
     * height is down
     */
  public:
    std::vector<int> origin;
    int length;
    int height;

    Block(std::vector<int> origin, int length, int height);
    Block();
};
