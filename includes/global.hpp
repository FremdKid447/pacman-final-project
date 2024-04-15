#ifndef GLOBAL_HPP
#define GLOBAL_HPP
//Variables and enums that we are using globally

constexpr unsigned int cell_size = 16;
constexpr unsigned int map_height = 21;
constexpr unsigned int map_width = 21;
constexpr unsigned int screen_resize = 2;
constexpr unsigned int frame_duration = 16667;
constexpr unsigned int font_height = 16;
constexpr unsigned int pacman_animation_speed = 2;
constexpr unsigned int pacman_death_frames = 12;
constexpr unsigned int ghost_speed = 1;
constexpr unsigned int ghost_animation_speed = 4;
constexpr unsigned int ghost_animation_frames = 6;

enum Cell { Door, Empty, Energizer, Pellet, Wall };
enum Color { Red, Pink, Blue, Orange };
enum Direction { Right, Left, Up, Down };
struct Location {
  int x = 0;
  int y = 0;
};

#endif
