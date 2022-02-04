#include "UI.h"

void UI::Window()
{

}

void UI::MouseControl(sf::Event& event, sf::RenderWindow& window, sf::View& Camera, sf::Vector2f& CursorPosition, bool& CursorMoving)
{
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                CursorMoving = true;
                CursorPosition = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
            }
            else if (event.mouseButton.button == sf::Mouse::Right)
            {
                // none yet
            }
            break;

        case sf::Event::MouseButtonReleased:
            // Mouse button is released, no longer move
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                CursorMoving = false;
            }
            break;

        case sf::Event::MouseMoved:
        {
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

        }
    }
}



void UI::KeyboardControl(sf::RenderWindow& Window, const sf::Event& Event, sf::View Camera, bool& Menu)
{
    switch (Event.type)
    {
    case sf::Event::KeyPressed:
        if (Event.key.code == sf::Keyboard::Escape)
        {
            Window.close();
        }
        break;
    case sf::Event::KeyReleased:
        if (Event.key.code == sf::Keyboard::M)
        {
            static bool toggle = false;
            if (toggle == true)
            {
                Menu = false;
                toggle = false;
            }
            else
            {
                Menu = true;
                toggle = true;
            }
        }
        break;
    }
}

void UI::Draw()
{

}

void Menus::MainMenu()
{
    sf::RectangleShape rectangle1;
    rectangle1.setFillColor(sf::Color(128, 128, 128, 128));
    rectangle1.setSize(sf::Vector2f(ScreenWidth, ScreenHeight));
    rectangle1.setPosition(Camera.x, Camera.y);
    window.draw(rectangle1);
}
