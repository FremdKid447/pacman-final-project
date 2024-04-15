#include <array>
#include <cmath>

#include "global.hpp"

bool collision(bool collect_pellets, bool use_door, int x, int y, std::array<std::array<Cell, map_height>, map_width>& map);