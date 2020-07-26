#include <SFML/Graphics.hpp>

#include "Scenes/SceneManager.h"
#include <memory>
#include "Scenes/Scene.h"
#include "Scenes/Level1.h"

jam::SceneManager manager;

int main() {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Magenta);

    jam::Scene scene1(window, std::string("Scene 1"));
    std::shared_ptr<jam::Level1> level1 = std::make_shared<jam::Level1>(window);
    static bool flip;

    manager.addScene(scene1);
    manager.addScene(level1);

    manager.setCurrentScene("Scene 1");

    while (window->isOpen()) {
        manager.update();
        manager.getCurrentScene().update();


        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                flip = !flip;
            }
            
            if (!flip)manager.setCurrentScene(scene1.getName());
            else manager.setCurrentScene(level1->getName());

        }

        window->clear();
        static sf::CircleShape shape(10.f);
        shape.setFillColor(sf::Color::Red);
        window->draw(shape);
        manager.getCurrentScene().render();
        window->display();

    }

    return 0;
}