#pragma once
#include <SFML/Graphics.hpp>

class Tile {
public:
	Tile(const float SIZE);
	void draw(sf::RenderWindow &window);

	void setTexture(sf::Texture &tileset, unsigned int tileID) { 
		rect.setTexture(&tileset); 
		sf::Vector2u tilesetSize = tileset.getSize();
		tilesetSize.x /= 1; // Dividing by the number of tiles in the x axis
		tilesetSize.y /= 1; // Dividing by the number of tiles in th ey axis

		rect.setTexture(&tileset);
		rect.setTextureRect(sf::IntRect(tilesetSize.x * (tileID - 1), tilesetSize.y * (tileID - 1), tilesetSize.x, tilesetSize.y));
	}
	void setPosition(const float posX, const float posY) { rect.setPosition(posX, posY); }

private:
	sf::RectangleShape rect;
};
