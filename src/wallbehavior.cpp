#include "wallbehavior.hpp"

bool collision(bool collect_pellets, bool use_door, int x, int y, std::array<std::array<Cell, map_height>, map_width>& map) {
	bool output;
    //casting to get the exact location so that collision works correctly
	double wall_x = x / static_cast<double>(cell_size);
	double wall_y = y / static_cast<double>(cell_size);
	for (int i = 0; i < 4; ++i) {
		int new_x = 0;
		int new_y = 0;
        if (i == 0) { //top left
            new_x = static_cast<int>(floor(wall_x));
			new_y = static_cast<int>(floor(wall_y));
        } else if (i == 1) { //top right
			new_x = static_cast<int>(ceil(wall_x));
			new_y = static_cast<int>(floor(wall_y));
        } else if (i == 2) { //bottom left
			new_x = static_cast<int>(floor(wall_x));
			new_y = static_cast<int>(ceil(wall_y));
		} else if (i == 3) { //bottom right
            new_x = static_cast<int>(ceil(wall_x));
			new_y = static_cast<int>(ceil(wall_y));
        }

        if (Cell::Wall == map[new_x][new_y]) {
		    output = true;
		}
        if (Cell::Pellet == map[new_x][new_y]){
		output = true;
			map[new_x][new_y] = Cell::Empty;
		}
		if (Cell::Energizer == map[new_x][new_y]){
			output = true;
			map[new_x][new_y] = Cell::Empty;
		}
		//if this position is inside the map
		//if (0 <= x &&  map_width > x && 0 <= y && map_height > y) {
    }
	return output;
}
