#include "window.h"

std::unique_ptr<sf::RenderWindow> CreateWindow(std::array<int, 2> WindowDimensions, std::string title)
{
    auto ptr = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(WindowDimensions[0], WindowDimensions[1]), title));
    return ptr;
}