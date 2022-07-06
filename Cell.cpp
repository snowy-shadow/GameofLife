#include "Cell.h"

Cell::Cell()
{
	m_position = { 0, 0 };

	m_shape.setSize(sf::Vector2f(1, 1));

	m_shape.setOutlineColor(sf::Color::White);

	m_state = DEAD;
}

sf::FloatRect Cell::getPosition()
{
	return m_shape.sf::Shape::getGlobalBounds();
}

void Cell::setState(bool state)
{
	m_state = state;

	m_state ? m_shape.setFillColor(sf::Color::White) : m_shape.setFillColor(sf::Color::Black);
}

bool Cell::getState()
{
	return m_state;
}

void Cell::setPosition(std::array<float, 2> coordinate)
{
	m_position = coordinate;
}
