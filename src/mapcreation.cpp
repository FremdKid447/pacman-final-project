#include "mapcreation.hpp"

std::array<std::array<Cell, map_height>, map_width> convert_sketch(const std::array<std::string, map_height>& map_sketch, std::array<Ghost, 4>& ghosts, Pacman& pacman) {
	std::array<std::array<Cell, map_height>, map_width> map{};
	for (unsigned char a = 0; a < map_height; a++) {
		for (unsigned char b = 0; b < map_width; b++) {
			//Every cell should be initialized to being empty
			map[b][a] = Cell::Empty;
			if (map_sketch[a][b] == '#') {
				map[b][a] = Cell::Wall;
			} else if (map_sketch[a][b] == '.') {
				map[b][a] = Cell::Pellet;
			} else if (map_sketch[a][b] == 'o') {
				map[b][a] = Cell::Energizer;
			} else if (map_sketch[a][b] == 'P') {
				pacman.SetLocation(cell_size * b, cell_size * a);
			} else if (map_sketch[a][b] == 'R') { //red
				ghosts[0].SetLocation(cell_size * b, cell_size * a);
			} else if (map_sketch[a][b] == 'I') { //pink
				ghosts[1].SetLocation(cell_size * b, cell_size * a);
			} else if (map_sketch[a][b] == 'B') { //blue
				ghosts[2].SetLocation(cell_size * b, cell_size * a);
			} else if (map_sketch[a][b] == 'O') { //orange
				ghosts[3].SetLocation(cell_size * b, cell_size * a);
			}
		}
	}
	return map;
}
