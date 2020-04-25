#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.clear(sf::Color::Black);

    for (int i=0; i<800; i++) {
        double v = 500 - std::pow(((i - 400.0)/400.0), 2) * 300; 
        sf::Vertex vertices[] = {
            sf::Vertex(sf::Vector2f(i, v), sf::Color::Green),
        };
        window.draw(vertices, 1, sf::PrimitiveType::Points);
    }

    window.display();
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.waitEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
