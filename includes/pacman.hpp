#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <array>
#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>

#include "global.hpp"
#include "wallbehavior.hpp"

class Pacman {
public: 
    Pacman();
    
    bool GetAnimationOver();
	bool GetDead();
	Direction GetDirection();
	unsigned int GetEnergizerTimer();
    Location GetLocation();
    int GetNumLives();
    int GetScore();
    
    void AddScore(int points);

	void Draw(bool victory, sf::RenderWindow& window);
	void Reset();
    
	void SetAnimationTimer(unsigned int animation_timer);
	void SetLocation(int x, int y);
	void Update(std::array<std::array<Cell, map_height>, map_width>& map);

    void Die();

private:
    int num_lives = 3;
    int score;
    bool dead;
    Direction direction;
    bool animation_over;

	size_t animation_timer;
	size_t energizer_timer;

	Location location;
};

#endif
