#include <SFML/Graphics.hpp>

#include "Scenes/SceneManager.h"
#include <Entities/EntityManager.h>
#include <memory>
#include "Scenes/Scene.h"
#include "Scenes/Level1.h"

std::unique_ptr < jam::SceneManager> manager = std::make_unique<jam::SceneManager>();
std::unique_ptr<jam::EntityManager> entityManager = std::make_unique<jam::EntityManager>();

int main() {
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Magenta);

    jam::Scene scene1(window, std::string("Scene 1"));
    std::shared_ptr<jam::Level1> level1 = std::make_shared<jam::Level1>(window);
    static bool flip;

    std::shared_ptr<jam::Player> player = std::make_shared<jam::Player>(sf::Vector2f(50, 50), sf::Rect<float>(50, 50, 50, 50));
    entityManager->addPlayer(*player);
    manager->addScene(scene1);
    manager->addScene(level1);
    manager->setCurrentScene("Scene 1");

    jam::Entity ent = jam::Entity();
    sf::Texture tex;
    if (!tex.loadFromFile("res/molten.jpg")) std::cout << "FAILED TO LOAD" << std::endl;
    ent.setTexture(tex, 50, 100);
    entityManager->addEntity(std::make_shared<jam::Entity>(ent));
    ent.setSize(sf::Vector2f(10.0f, 20.0f));
    sf::View view(sf::FloatRect(entityManager->getPlayer()->getPosition(), sf::Vector2f(400.0f, 400.0f)));
    sf::Clock clock;
    float deltaTime;
    while (window->isOpen()) {
        manager->update();
        entityManager->update();
        manager->getCurrentScene().update();
        view.setCenter(entityManager->getPlayer()->getPosition());
        window->setView(view);

        deltaTime = clock.restart().asSeconds();


        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::E) {
                    flip = !flip;
                }
            }
            if (event.type == sf::Event::Resized) {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                window->setView(sf::View(visibleArea));
            }
            if (!flip)manager->setCurrentScene(scene1.getName());
            else manager->setCurrentScene(level1->getName());

        }

        window->clear();
        static sf::CircleShape shape(10.f);
        shape.setFillColor(sf::Color::Red);
        window->draw(shape);

        static sf::CircleShape shape1(10.f);
        shape1.setPosition(sf::Vector2f(50.0f, 10.0f));
        shape1.setFillColor(sf::Color::Magenta);
        window->draw(shape1);
        manager->getCurrentScene().render();
        entityManager->render(window);
        window->display();



    }

    return 0;
}