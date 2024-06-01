#pragma once
#include <SFML/Graphics.hpp>

class Tile {
public:
	Tile(const float SIZE);
	void draw(sf::RenderWindow &window);

	void setTexture(sf::Texture &texture) { rect.setTexture(&texture); }
	void setPosition(const float posX, const float posY) { rect.setPosition(posX, posY); }

private:
	sf::RectangleShape rect;
};
