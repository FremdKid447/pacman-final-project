#ifndef GHOST_HPP
#define GHOST_HPP

#include <array>
#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>

#include "global.hpp"
#include "pacman.hpp"

class Ghost {
public: 
    Ghost(Color color);

	bool PacmanCollision(const Location& pacman_location);

	float GetTargetDistance(Direction direction);

	void Draw(bool i_flash, sf::RenderWindow& i_window);
	void Reset(const Location& home, const Location& home_exit);
	void SetLocation(int x, int y);
	void SwitchMode();
	void Update(unsigned char level, std::array<std::array<Cell, map_height>, map_width>& map, Ghost& ghost_0, Pacman& pacman);
	void UpdateTarget(std::string pacman_direction, const Location& ghost_location, const Location& pacman_location);

	Location GetLocation();
    Direction GetDirection();
    bool GetNeutralized();
    bool GetScared();

private:
    bool neutralized_ = false;
    bool scared_ = false;
    Color color_;
    Direction direction_;
    
    int frightened_timer_;
	short animation_timer_;
    
    Location current_location_;
    Location home_;
    Location home_exit_;
    Location target_;
};

#endif
