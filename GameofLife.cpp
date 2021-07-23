// GameofLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "World.h"


int main()
{
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

    Entities test;


    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                // Mouse button is pressed, get the position and set moving as active
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    CursorMoving = true;
                    CursorPosition = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                }
                else if (event.mouseButton.button == sf::Mouse::Left)
                {
                    CursorPosition = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                }
                break;
            case sf::Event::MouseButtonReleased:
                // Mouse button is released, no longer move
                if (event.mouseButton.button == sf::Mouse::Right) {
                    CursorMoving = false;
                }
                if (event.mouseButton.button == sf::Mouse::Left)
                    break;

            case sf::Event::MouseMoved:
            {
                // Ignore mouse movement unless a button is pressed (see above)
                if (!CursorMoving)
                    break;
                // Determine the new position in world coordinates
                const sf::Vector2f NewCursorPosition = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                // Determine how the cursor has moved
                // Swap these to invert the movement direction
                const sf::Vector2f CursorMovedDistance = CursorPosition - NewCursorPosition;
                // Move our view accordingly and update the window
                Camera.move(CursorMovedDistance);
                window.setView(Camera);

                // Save the new position as the old one
                // We're recalculating this, since we've changed the view
                CursorPosition = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
                break;
            }

            case sf::Event::MouseWheelMoved:
            {
                float Zoom = 0;
                if (event.mouseWheel.delta <= -1 && Camera.getSize().x < 2500)
                {
                    Zoom = 1.1f;
                    Camera.zoom(Zoom);
                    window.setView(Camera);
                }
                else if (event.mouseWheel.delta >= 1)
                {
                    Zoom = 0.9f;
                    Camera.zoom(Zoom);
                    window.setView(Camera);
                }
                std::cout << Camera.getSize().x << "," << Camera.getSize().y << "\n\n";
                break;
            }
            }

            window.clear();
            //test.entites();
            window.display();
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
