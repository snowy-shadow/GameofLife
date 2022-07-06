#pragma once

#ifndef CELL_H
#define CELL_H	

#include <SFML/Graphics.hpp>
#include <array>

enum CellState
{
	ALIVE = true,
	DEAD = false
};

class Cell
{
	sf::RectangleShape m_shape;

	std::array<float, 2> m_position;

	bool m_state;

public:

	Cell();

	void setState(bool state);

	void setPosition(std::array<float, 2> coordinate);

	bool getState();

	sf::FloatRect getPosition();
};

#endif