#include "map.h"

void map::createMap(std::array<int, 2> MapDimention)
{
	m_MapDimension = MapDimention;

	for (float i = 0; i < std::get<1>(MapDimention); i++) // y
	{
		for (float j = 0; j < std::get<0>(MapDimention); j++) // x
		{
			auto NewCell = std::unique_ptr<Cell>(new Cell);
			NewCell->setPosition({i, j});
			cells.push_back(std::move(NewCell));
		}
	}
}

void map::move(std::array<float, 2> move)
{
	for (auto& iter : cells)
	{
		iter->setPosition({ iter->getPosition().left + move[0], iter->getPosition().top - move[1] });
	}
}
