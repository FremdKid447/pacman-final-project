#include "global.hpp"
#include <array>
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "mapcreation.hpp"
#include "createmap.hpp"
#include "pacman.hpp"
#include "ghost.hpp"

int main() {
    unsigned lag = 0;
    
    std::chrono::time_point<std::chrono::steady_clock> previous_time;

	//pacman map with only walls for now
    std::array<std::string, map_height> map_drawing = {
		" ################### ",
		" #........#........# ",
		" #o##.###.#.###.##o# ",
		" #.................# ",
		" #.##.#.#####.#.##.# ",
		" #....#...#...#....# ",
		" ####.### # ###.#### ",
		"    #.#   R   #.#    ",
		"#####.# ## ## #.#####",
		"     .  #IBO#  .     ",
		"#####.# ##### #.#####",
		"    #.#       #.#    ",
		" ####.# ##### #.#### ",
		" #........#........# ",
		" #.##.###.#.###.##.# ",
		" #o.#.....P.....#.o# ",
		" ##.#.#.#####.#.#.## ",
		" #....#...#...#....# ",
		" #.######.#.######.# ",
		" #.................# ",
		" ################### "
	};

	std::array<std::array<Cell, map_height>, map_width> map{};
    sf::Event event;

	sf::RenderWindow window(sf::VideoMode(cell_size * map_width * screen_resize, (font_height + cell_size * map_height) * screen_resize), "Pac-Man", sf::Style::Close);
    window.setView(sf::View(sf::FloatRect(0, 0, cell_size * map_width, font_height + cell_size * map_height)));
    previous_time = std::chrono::steady_clock::now();

	Pacman pacman;
	std::array<Ghost, 4> ghosts = {Ghost(Red), Ghost(Pink), Ghost(Blue), Ghost(Orange)};
	
	map = convert_sketch(map_drawing, ghosts, pacman);

	while (window.isOpen()) {
		unsigned delta_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time).count();
		lag += delta_time;
		previous_time += std::chrono::microseconds(delta_time);

		//This part of the code reduces the lag in the game. It also ensures that the user can close the game.
		while (frame_duration <= lag) {
			lag -= frame_duration;
			while (1 == window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			pacman.Update(map);
		}
		if (frame_duration > lag) {
			window.clear();
			draw_map(map, window);
			
			pacman.Draw(true, window);
			for (Ghost& ghost : ghosts) {
				ghost.Draw(true, window);
			}
			window.display();
		}
	}
}
