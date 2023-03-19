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
    bool gameOver;

    protected:
        void events();
        void draw();
        void game();
        void movePipes();
        void setAnimeBird();
        void moveBird();
    
    public:
        FlappyBird();
        void run();

};