#pragma once

#ifndef MAP_H
#define MAP_H

#include <array>
#include <memory>
#include "Cell.h"

class map
{
	std::vector<std::unique_ptr<Cell>> cells;

	std::array<int, 2> m_MapDimension;

public:
	void createMap(std::array<int, 2> MapDimention);

	void move(std::array<float, 2> move);

};

#endif