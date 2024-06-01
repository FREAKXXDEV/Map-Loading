#include <tile.h>

Tile::Tile(const float SIZE)
	:rect(sf::Vector2f(SIZE, SIZE)) {

}

void Tile::draw(sf::RenderWindow &window) {
	window.draw(rect);
}
