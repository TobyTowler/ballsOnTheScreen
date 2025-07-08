#include "blocks.h"
#include "Window/Sensor.hpp"
#include <cstdlib>

Block::Block()
    // : origin(rand() % 800, rand() % 600), length(rand() % 130 + 30), height(rand() % 130 + 30),
    : originx(rand() % 800), originy(rand() % 600), length(rand() % 130 + 30),
      height(rand() % 130 + 30), health(rand() % 200) {}

// Block::Block(std::vector<float> origin, int length, int height, int health)
//     : origin(origin), length(length), height(height), health(health) {}
