#ifndef CREATEMAP_HPP
#define CREATEMAP_HPP

#include <array>
#include <SFML/Graphics.hpp>
#include "global.hpp"

void draw_map(const std::array<std::array<Cell, map_height>, map_width>& i_map, sf::RenderWindow& i_window);

#endif