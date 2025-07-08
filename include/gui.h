#pragma once
#include "Graphics/CircleShape.hpp"
#include "Graphics/RectangleShape.hpp"
#include "Graphics/Text.hpp"
#include <SFML/Graphics.hpp>

struct BlockDrawings {
    sf::RectangleShape block;
    sf::Text text;
};

void runGUI(int numberOfBalls);

sf::CircleShape drawBalls();

BlockDrawings drawBlocks();
