#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    sf::RenderTexture rt;
    if (!rt.create(800, 600)) {
        std::cerr << "Nem tudtam a texture-t letrehozni." << std::endl;
        std::exit(1);
    }
    rt.clear(sf::Color::Black);
    rt.display();

    int i = 0;
    sf::Clock clock;
    sf::Sprite sprite;
    sprite.setTexture(rt.getTexture());
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (i < 800 && clock.getElapsedTime().asMilliseconds() % 100 == 0) {
            double v = 500 - std::pow(((i - 400.0)/400.0), 2) * 300; 
            sf::Vertex vertices[] = {
                sf::Vertex(sf::Vector2f(i, v), sf::Color::Green),
            };
            rt.draw(vertices, 1, sf::PrimitiveType::Points);
            rt.display();
            i++;
        }

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }

    return 0;
}
