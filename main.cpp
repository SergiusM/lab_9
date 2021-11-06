#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;
int main()
{
    int windowWidth = 800;
    int windowHeight = 600;
    int x1, x2, x3, y1, y2, y3;
    x1 = x2 = x3 = 100;
    y1 = 100;
    y2 = 250;
    y3 = 450;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Lab 9 works!");
    sf::CircleShape shape1(50.0);
    shape1.setOrigin(100, 100);
    shape1.setFillColor(sf::Color::Blue);
    shape1.setPosition(x1, y1);

    sf::CircleShape shape2(75.0);
    shape2.setOrigin(100, 100);
    shape2.setFillColor(sf::Color::Yellow);
    shape2.setPosition(x2, y2);

    sf::CircleShape shape3(100.0);
    shape3.setOrigin(100, 100);
    shape3.setFillColor(sf::Color::Green);
    shape3.setPosition(x3, y3);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (x1 < 800)
            x1 += 20;
        shape1.setPosition(x1, y1);

        if (x2 < 800 - 50)
            x2 += 25;
        shape2.setPosition(x2, y2);

        if (x3 < 800 - 100)
            x3 += 10;
        shape3.setPosition(x3, y3);

        window.clear();
        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);
        window.display();

        std::this_thread::sleep_for(40ms);
    }


    return 0;
}
