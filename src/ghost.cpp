#include "ghost.hpp"

Ghost::Ghost(Color color): color_(color) {}

bool Ghost::PacmanCollision(const Location& pacman_location) {
  if (current_location_.x > pacman_location.x - cell_size && current_location_.x < pacman_location.x + cell_size) {
    if (current_location_.y > pacman_location.y - cell_size && current_location_.y < pacman_location.y + cell_size) {
      return true;
    }
  } else {
    return false;
  }
}

float Ghost::GetTargetDistance(Direction direction) {
  int x = current_location_.x;
  int y = current_location_.y;
  
  if (direction == Right) {
    x += ghost_speed;
  } else if (direction == Left) {
    x -= ghost_speed;
  } else if (direction == Up) {
    y += ghost_speed;
  } else if (direction == Down) {
    y -= ghost_speed;
  }
  return static_cast<float>(sqrt(pow(x - target_.x, 2) + pow(y - target_.y, 2)));
}

void Ghost::Draw(bool flash, sf::RenderWindow& window) {
  unsigned int body_frame = static_cast<size_t>(floor(animation_timer_ / static_cast<float>(ghost_animation_speed)));
  
  sf::Sprite ghost_body;
  sf::Sprite ghost_face;
  sf::Texture ghost_texture;

  ghost_texture.loadFromFile("resources/Sprites/Ghosts.png");
  ghost_body.setTexture(ghost_texture);
  ghost_body.setPosition(current_location_.x, current_location_.y);
  ghost_body.setTextureRect(sf::IntRect(cell_size * body_frame, 0, cell_size, cell_size));
  ghost_face.setTexture(ghost_texture);
  ghost_face.setPosition(current_location_.x, current_location_.y);
  
  if (neutralized_ == false && scared_ == false) {
    if (color_ == Red) {
      ghost_body.setColor(sf::Color(255, 0, 0));
    }
    else if (color_ == Pink) {
      ghost_body.setColor(sf::Color(255, 182, 255));
    }
    else if (color_ == Blue) {
      ghost_body.setColor(sf::Color(0, 0, 255));
    }
    else if (color_ == Orange) {
      ghost_body.setColor(sf::Color(255, 182, 85));
    }
    ghost_face.setTextureRect(sf::IntRect(cell_size * direction_, cell_size, cell_size, cell_size)); 
    window.draw(ghost_body);
  }
  else if (neutralized_ == true && scared_ == false) {
    ghost_body.setColor(sf::Color(36, 36, 255));
    ghost_face.setTextureRect(sf::IntRect(cell_size * 4, cell_size, cell_size, cell_size));
    
    if (flash == true && body_frame % 2 == 0) {
      ghost_body.setColor(sf::Color(255, 255, 255));
      ghost_face.setColor(sf::Color(255, 0, 0));
    }
    else {
      ghost_body.setColor(sf::Color(36, 36, 255));
      ghost_face.setColor(sf::Color(255, 255, 255));
    }
    window.draw(ghost_body);
  }
  else if (neutralized_ == false && scared_ == true) {
    ghost_face.setTextureRect(sf::IntRect(cell_size * direction_, 2 * cell_size, cell_size, cell_size));
  }
  
  window.draw(ghost_face);
  
  animation_timer_ = (1 + animation_timer_) % (ghost_animation_frames * ghost_animation_speed);
}
  

void Ghost::Reset(const Location& home, const Location& home_exit) {
  direction_ = Up;
  neutralized_ = false;
  scared_ = false;
  
  frightened_timer_ = 0;
  animation_timer_ = 0;
  
  home_ = home;
  home_exit_ = home_exit;
  target_ = home_exit;
}

void Ghost::SetLocation(int x, int y) {
  current_location_ = {x, y};
}

// void Ghost::Update(unsigned char level, std::array<std::array<Cell, map_height>, map_width>& map, Ghost& ghost_0, Pacman& pacman);
// void Ghost::UpdateTarget(std::string pacman_direction, const Location& ghost_location, const Location& pacman_location);

Location Ghost::GetLocation() {
  return current_location_;
}

Direction Ghost::GetDirection() {
  return direction_;
}

bool Ghost::GetNeutralized() {
  return neutralized_;
}

bool Ghost::GetScared() {
  return scared_;
}
