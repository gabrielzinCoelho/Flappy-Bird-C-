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
    gameOver = false;

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

    for(auto &p : pipes){
        window->draw(p);
    }
    window->draw(*bird);

    window->display();

}

void FlappyBird::run(){

    while(window->isOpen()){
        events();
        game();
        draw();

        ++count;
        if(count >= 300)
            count = 0;
    }

}

void FlappyBird::movePipes(){

    if(count%150 == 0){
        int pos = std::rand() % 275 + 175;
        pipeBottom->setPosition(1000, pos + space);
        pipeTop->setPosition(1000, pos);

        pipes.push_back(*pipeBottom);
        pipes.push_back(*pipeTop);

    }

    for(std::size_t i{0}; i < pipes.size(); i++){

        if(pipes[i].getGlobalBounds().intersects(bird->getGlobalBounds())){
            gameOver = true;
        }

        if(pipes[i].getPosition().x < -100){
            pipes.erase(pipes.begin() + i);
        }

        pipes[i].move(-4.f, 0);

    }

}

void FlappyBird::game(){

   if(gameOver)
        return;
    setAnimeBird();
    moveBird();
    movePipes();

}

void FlappyBird::setAnimeBird(){

    frame+= 0.15f;

    if(frame>3)
        frame-=3;
    
    bird->setTextureRect(sf::IntRect(34 * (int)frame, 0, 34, 24)); 

}

void FlappyBird::moveBird(){

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        gravity = -6.f;
        bird->setRotation(-frame - 10.f);
    }
    else{
        gravity += 0.5f;
        bird->setRotation(frame - 10.f);
    }

    bird->move(0, gravity);

}