#ifndef MAPCREATION_HPP
#define MAPCREATION_HPP

#include <array>
#include <string>
#include <SFML/Graphics.hpp>

#include "global.hpp"
#include "pacman.hpp"
#include "ghost.hpp"

std::array<std::array<Cell, map_height>, map_height> convert_sketch(const std::array<std::string, map_height>& i_map_sketch, std::array<Ghost, 4>& ghost_positions, Pacman& pacman);

#endif