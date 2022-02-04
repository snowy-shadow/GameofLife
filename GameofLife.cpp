// GameofLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UI.h"

int main()
{
    void Initalize();
    // Screen
    int ScreenWidth = 1280, ScreenHeight = 720;
    sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Game of Life");

    // Anti aliasing
    sf::ContextSettings AntiAliasing;
    AntiAliasing.antialiasingLevel = 8;

    // FPS Limit
    window.setFramerateLimit(60);

    // Camera
    sf::View Camera(sf::Vector2f(0, 0), sf::Vector2f(300, 200));
    window.setView(Camera);

    // Cursor Position
    sf::Vector2f CursorPosition;
    bool CursorMoving = false;

    // Event
    sf::Event event;

    World world;

    UI UI;

    bool menu = false;
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));


    std::cout << Camera.getSize().x << "," << Camera.getSize().y;
    while (window.isOpen())
    {
        // MouseControls
        UI.MouseControl(event, window, Camera, CursorPosition, CursorMoving);
        UI.KeyboardControl(window, event, Camera, menu);
        window.clear();
        window.draw(rectangle);
        //                                           Include Vectors for draw function
        if (menu == true)
        {

        }
        window.display();
    }
}




