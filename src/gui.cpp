#include "gui.h"
#include "Graphics/CircleShape.hpp"
#include "balls.h"
#include "blocks.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

void runGUI(int numberOfBalls) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Ball Spawner GUI");
    window.setFramerateLimit(240);

    std::vector<Ball> balls(numberOfBalls);

    Block block1 = Block(std::vector<int>{300, 400}, 30, 30);
    Block block2 = Block(std::vector<int>{200, 200}, 30, 30);
    Block block3 = Block(std::vector<int>{400, 700}, 30, 30);

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        // for (Ball &b : balls) {
        for (int i = 0; i < balls.size(); i++) {
            sf::CircleShape circle(5);
            // circle.setPosition(b.getPos());
            circle.setPosition(balls[i].getPos());
            circle.setFillColor(sf::Color::White);
            window.draw(circle);
            balls[i].updatePos();
            std::cout << "Updated Ball " << i << "\n";
            balls[0].printAngle();
        }

        window.display();
    }
}
