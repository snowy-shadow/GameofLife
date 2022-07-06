#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <array>
#include <memory>

std::unique_ptr<sf::RenderWindow> CreateWindow(std::array<int, 2> WindowDimensions = {1280, 720}, std::string title = "");

#endif