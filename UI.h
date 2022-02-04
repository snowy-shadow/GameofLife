#pragma once
#include <iostream>
#include "World.h"

class UI
{
public:
	virtual void Window();
	void MouseControl(sf::Event&, sf::RenderWindow&, sf::View&, sf::Vector2f&, bool&);
	void KeyboardControl(sf::RenderWindow&, const sf::Event&, sf::View, bool&);
	void Draw();
};

class Menus : UI
{
public:
	void MainMenu();

};
