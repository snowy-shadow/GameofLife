#pragma once

#ifndef UI_H
#define UI_H


#include <iostream>
#include <vector>
#include "World.h"

class UI : public sf::Drawable // inherit from sf::Drawable to call .draw(); without access to window
{
protected:

	int m_ScreenWidth, m_ScreenHeight;

	sf::RenderWindow m_Window;

	// Anti aliasing
	sf::ContextSettings m_AntiAliasing;

public:
	UI(int, int);

	virtual void Window();

	void MouseControl(sf::Event&, sf::RenderWindow&, sf::View&, sf::Vector2f&, bool&);

	void KeyboardControl(sf::RenderWindow&, const sf::Event&, sf::View, bool&);

	void Draw();
};



class MainMenu : protected UI
{
public:
	void Window(); // if game is false -> main menu, else game menu. Only 1 at a time

};



class Settings : protected UI
{
public:
	void Window(); // create a semi transparent rectangle that fills the screen if pause is true
};

#endif
