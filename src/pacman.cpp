#include "global.hpp"
#include "pacman.hpp"

Pacman::Pacman(): animation_over(false), dead(false), num_lives(0), score(0), animation_timer(0), energizer_timer(0), direction(Left), location({0, 0}) {};
    
bool Pacman::GetAnimationOver() {
  return animation_over;
}

bool Pacman::GetDead() {
    return dead;
}

Direction Pacman::GetDirection() {
    return direction;
}

unsigned int Pacman::GetEnergizerTimer() {
    return energizer_timer;
}

Location Pacman::GetLocation() {
    return location;
}

int Pacman::GetNumLives() {
    return num_lives;
}

int Pacman::GetScore() {
    return score;
}

void Pacman::AddScore(int points) {
    score += points;
}

void Pacman::Draw(bool victory, sf::RenderWindow& window) {
	unsigned char frame = static_cast<unsigned char>(floor(animation_timer / static_cast<float>(pacman_animation_speed)));
	
	sf::Sprite pacman;
	sf::Texture pacman_texture;
	
	//don't change this: setPosition is part of sf
	pacman.setPosition(location.x, location.y);
	
	if (dead == true || victory == false) {
		if (animation_timer < pacman_death_frames * pacman_animation_speed) {
			animation_timer += 1;
			
			pacman_texture.loadFromFile("resources/Sprites/pacman_death.png");
			
			pacman.setTexture(pacman_texture);
			pacman.setTextureRect(sf::IntRect(cell_size * frame, 0, cell_size, cell_size));
			
			window.draw(pacman);
		}
		else {
			animation_over = true;
		}
	} else {
		pacman_texture.loadFromFile("resources/Sprites/pacman.png");
		
		pacman.setTexture(pacman_texture);
		
		if (direction == Up) {
			pacman.setTextureRect(sf::IntRect(cell_size * frame, cell_size * 0, cell_size, cell_size));
		} else if (direction == Down) {
			pacman.setTextureRect(sf::IntRect(cell_size * frame, cell_size * 1, cell_size, cell_size));
		} else if (direction == Right) {
			pacman.setTextureRect(sf::IntRect(cell_size * frame, cell_size * 2, cell_size, cell_size));
		} else if (direction == Left) {
			pacman.setTextureRect(sf::IntRect(cell_size * frame, cell_size * 3, cell_size, cell_size));
		}	
		window.draw(pacman);
	}
}
		
void Pacman::Reset() {
    animation_over = false;
    dead = false;

    num_lives = 0;
    score = 0;

    animation_timer = 0;
    energizer_timer = 0;
}

void Pacman::SetAnimationTimer(unsigned int animation_timer) {
    animation_timer = animation_timer;
}

void Pacman::SetLocation(int x, int y) {
    location = {x, y};
}

void Pacman::Update(std::array<std::array<Cell, map_height>, map_width>& map) {
	bool collision_right = collision(false, false, pacman_animation_speed + location.x, location.y, map);
	bool collision_up = collision(false, false, location.x, location.y - pacman_animation_speed, map);
	bool collision_left = collision(false, false, location.x - pacman_animation_speed, location.y, map);
	bool collision_down = collision(false, false, location.x, pacman_animation_speed + location.y, map);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (!collision_right) direction = Right;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (!collision_up) direction = Up;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (!collision_left) direction = Left;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (!collision_down) direction = Down;
	}
	
	if (!(collision_right && collision_left && collision_up && collision_down)) {
		if (direction == Right) {
			location.x += pacman_animation_speed;
		} else if (direction == Up) {
			location.y -= pacman_animation_speed;
		} else if (direction == Left) {
			location.x -= pacman_animation_speed;
		} else if (direction == Down)	{
			location.y += pacman_animation_speed;
		}
	}
}

void Pacman::Die() {
    dead = true;
	animation_timer = 0;
    num_lives -= 1;
}
