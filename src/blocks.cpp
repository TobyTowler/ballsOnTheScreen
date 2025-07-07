#include "blocks.h"
#include "Window/Sensor.hpp"
#include <cstdlib>

Block::Block() : origin(rand() % 800, rand() % 600), length(30), height(30) {}

Block::Block(std::vector<int> origin, int length, int height)
    : origin(origin), length(length), height(height) {}
