#include <SFML/Graphics.hpp>

#include "Scenes/SceneManager.h"
#include "Scenes/Scene.h"

jam::SceneManager manager;

int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Magenta);

    jam::Scene scene1(std::string("Scene 1"));
    jam::Scene scene2(std::string("Scene 2"));
    static bool flip;

    manager.addScene(&scene1);
    manager.addScene(&scene2);

    while (window.isOpen()) {
        manager.update();
        manager.getCurrentScene().update();


        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                flip = !flip;
            }
            
            if (flip)manager.setCurrentScene(scene1.getName());
            else manager.setCurrentScene(scene2.getName());

        }

        window.clear();
        window.draw(shape);
        window.display();

        manager.getCurrentScene().render();
    }

    return 0;
}