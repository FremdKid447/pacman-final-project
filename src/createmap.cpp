#include "createmap.hpp"

void draw_map(const std::array<std::array<Cell, map_height>, map_width>& map, sf::RenderWindow& window) {
    sf::RectangleShape wall_shape(sf::Vector2f(cell_size, cell_size));
    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile("resources/sprites/map_components.png");
    sprite.setTexture(texture);
	for (unsigned char x = 0; x < map_width; x++) {
		for (unsigned char y = 0; y < map_height; y++) {
            sprite.setPosition(static_cast<float>(cell_size * x), static_cast<float>(cell_size * y));
			wall_shape.setPosition(cell_size * x, cell_size * y);
            if (map[x][y] == Cell::Wall) {
                    wall_shape.setFillColor(sf::Color(36,36, 255));
                    window.draw(wall_shape);
            } else if (map[x][y] == Cell::Pellet) {
                sprite.setTextureRect(sf::IntRect(0, cell_size, cell_size, cell_size));
				window.draw(sprite);
            } else if (map[x][y] == Cell::Energizer) {
		    sprite.setTextureRect(sf::IntRect(cell_size, cell_size, cell_size, cell_size));
		    window.draw(sprite);
	    }
		}
	}
}
