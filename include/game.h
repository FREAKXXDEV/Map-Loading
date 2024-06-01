#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>
#include <settings.h>
#include <tile.h>

class Game {
public:
	Game();
	void run();

private:
	void processEvents();
	void update(float deltaTime);
	void render();
	void loadMap();

private:
	sf::RenderWindow window;
	sf::Texture rockTexture;
	std::vector<Tile*> rocks;
};
