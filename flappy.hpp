#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class FlappyBird{

    std::shared_ptr<sf::RenderWindow> window;
    sf::Texture bg, flappy, pipe;
    std::shared_ptr<sf::Sprite> background, bird, pipeTop, pipeBottom;
    std::vector<sf::Sprite> pipes;
    float gravity, frame, space;
    int count;

    protected:
        void events();
        void draw();
    
    public:
        FlappyBird();
        void run();

};