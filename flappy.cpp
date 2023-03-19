#include "flappy.hpp"

FlappyBird::FlappyBird(){

    window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(1000, 600),
        "Flappy Bird",
        sf::Style::Titlebar | sf::Style::Close
    );

    window->setPosition(sf::Vector2i(0, 0));
    window->setFramerateLimit(60);

    gravity = frame = {0.f};
    space = {160.f};
    count = {0};

    bg.loadFromFile("./resources/img/background.png");
    flappy.loadFromFile("./resources/img/flappy.png");
    pipe.loadFromFile("./resources/img/pipe.png");

    background = std::make_shared<sf::Sprite>();
    bird = std::make_shared<sf::Sprite>();
    pipeTop = std::make_shared<sf::Sprite>();
    pipeBottom = std::make_shared<sf::Sprite>();

    background->setTexture(bg);
    bird->setTexture(flappy);
    pipeTop->setTexture(pipe);
    pipeBottom->setTexture(pipe);

    bird->setPosition(500.f - flappy.getSize().x/2.f, 300.f - flappy.getSize().y/2.f);
    bird->setScale(2.f, 2.f);
    bird->setTextureRect(sf::IntRect(0, 0, 34, 24));

    pipeBottom->setScale(1.5f, 1.5f);
    pipeTop->setScale(1.5f, -1.5f);
    pipeTop->setPosition(100.f, 100.f);
    pipeBottom->setPosition(200.f, 100.f);

}

void FlappyBird::events(){
    auto e = std::make_shared<sf::Event>();
    while( window->pollEvent(*e) ){

        if(e->type == sf::Event::Closed)
            window->close();

    }
}

void FlappyBird::draw(){

    window->clear(sf::Color::Black);

    window->draw(*background);
    window->draw(*bird);
    window->draw(*pipeTop);
    window->draw(*pipeBottom);

    window->display();

}

void FlappyBird::run(){

    while(window->isOpen()){
        events();
        draw();
    }

}