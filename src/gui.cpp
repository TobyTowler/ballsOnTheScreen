#include "gui.h"
#include "Graphics/CircleShape.hpp"
#include "Graphics/Color.hpp"
#include "Graphics/Font.hpp"
#include "Graphics/RectangleShape.hpp"
#include "Graphics/Text.hpp"
#include "System/Vector2.hpp"
#include "balls.h"
#include "blocks.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

void runGUI(int numberOfBalls) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Ball Spawner GUI");

    std::vector<Ball> balls(numberOfBalls);

    std::vector<Block> blocks(4);

    sf::Clock clock;

    window.setFramerateLimit(0);
    window.setVerticalSyncEnabled(0);

    sf::CircleShape circle(5);
    circle.setFillColor(sf::Color::White);

    sf::Font font;
    if (!font.openFromFile("/usr/share/fonts/Adwaita/AdwaitaMono-Bold.ttf")) {
        std::cout << "NO FONT" << "\n";
    }
    sf::Text text(font);
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);

    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOutlineColor(sf::Color::Blue);
    rectangle.setOutlineThickness(2);

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        std::cout << "Number of Balls: " << balls.size() << "\n";

        // sf::Time deltaTime = clock.restart();
        // float fps = 1.0f / deltaTime.asSeconds();
        //
        // std::cout << "FPS: " << fps << "\n";

        window.clear(sf::Color::Black);

        for (int i = 0; i < balls.size(); i++) {
            circle.setPosition(balls[i].getPos());
            window.draw(circle);
            balls[i].updatePos(blocks);
            // std::cout << "Updated Ball " << i << "\n";
        }

        // for (int i = 0; i < blocks.size(); i++) {
        for (Block b : blocks) {

            if (b.health < 1) {
                balls.push_back(Ball(b.originx + b.length / 2, b.originy + b.height / 2));
            }

            blocks.erase(std::remove_if(blocks.begin(), blocks.end(),
                                        [](const Block &b) { return b.health < 1; }),
                         blocks.end());
        }

        for (int i = 0; i < blocks.size(); i++) {
            rectangle.setPosition(sf::Vector2f(blocks[i].originx, blocks[i].originy));
            rectangle.setSize(sf::Vector2f(blocks[i].length, blocks[i].height));
            window.draw(rectangle);

            text.setString(std::to_string(blocks[i].health));
            text.setPosition(sf::Vector2f(blocks[i].originx + 5, blocks[i].originy + 5));
            window.draw(text);
        }
        if (rand() % 250000 < numberOfBalls) {
            Block block;
            blocks.push_back(block);
        }

        window.display();
    }
}
