#include "flappy.hpp"

int main()
{
    auto flappy = std::make_shared<FlappyBird>();
    flappy->run();

    return 0;
}