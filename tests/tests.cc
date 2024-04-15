#include "catch.hpp"
#include "mapcreation.hpp"
#include "global.hpp"
#include "pacman.hpp"
#include "createmap.hpp"
#include "ghost.hpp"
#include <array>

Pacman pacman;
std::array<Ghost, 4> ghosts = {Ghost(Red), Ghost(Pink), Ghost(Blue), Ghost(Orange)};

TEST_CASE("Convert sketch of map") {
  std::array<std::string, map_height> test_map = {
	  "#                    ",
	  " .                   ",
	  "  #                  ",
    "    #                ",
    "     o               ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     "
	};
  std::array<std::array<Cell, map_height>, map_width> map{};
  map = convert_sketch(test_map, ghosts, pacman);
  REQUIRE(map[0][0] == Cell::Wall);
  REQUIRE(map[1][1] == Cell::Pellet); 
  REQUIRE(map[2][2] == Cell::Wall);
  REQUIRE(map[4][3] == Cell::Wall);
  REQUIRE(map[5][4] == Cell::Energizer);
}

TEST_CASE("Empty map") {
  std::array<std::string, map_height> empty_map = {
	  "                     ",
	  "                     ",
	  "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     ",
    "                     "
	};
  std::array<std::array<Cell, map_height>, map_width> hollow_map{};
  hollow_map = convert_sketch(empty_map, ghosts, pacman);
  for (size_t i = 0; i < map_height; ++i) {
    for (size_t j = 0; j < map_width; ++j) {
      REQUIRE(hollow_map[i][j] == Cell::Empty);
    }
  }
}