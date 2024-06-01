#include <game.h>

Game::Game()
	: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Map Loading", sf::Style::Close) {

	loadMap();
}

void Game::run() {
	sf::Clock clock;
	float deltaTime;
	while (window.isOpen()) {
		deltaTime = clock.restart().asSeconds();
		processEvents();
		update(deltaTime);
		render();
	}
}

void Game::processEvents() {
	sf::Event evnt;
	while (window.pollEvent(evnt)) {
		if (evnt.type == sf::Event::KeyReleased && evnt.key.code == sf::Keyboard::Escape 
			|| evnt.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void Game::update(float deltaTime) {
	// Update Game Objects
}

void Game::render() {
	window.clear();

	for (const auto &tile : rocks)
		tile->draw(window);
	window.display();
}

void Game::loadMap() {
	tmx::Map map;
	map.load("data/map.tmx");
	const auto &tilesets = map.getTilesets();
	rockTileset.loadFromFile(tilesets[0].getImagePath().substr(5));

	for (const auto &layer : map.getLayers()) {
		if (layer->getType() == tmx::Layer::Type::Tile) {
			if (layer->getName() == "rocks") {
				const tmx::TileLayer &rockLayer = static_cast<const tmx::TileLayer&>(*layer);
				const std::vector<tmx::TileLayer::Tile> &tiles = rockLayer.getTiles();

				float posX = 0;
				float posY = 0;
				for (size_t i = 0; i < tiles.size(); ++i) {
					if (posX > 19) {
						posX = 0;
						posY++;
					}
					
					if (tiles[i].ID) {
						// if tile id > 19 then y ++ x = 0;
						Tile *rock = new Tile(TILE_SIZE);
						rock->setTexture(rockTileset, (unsigned int)tiles[i].ID);
						rock->setPosition(posX * TILE_SIZE, posY * TILE_SIZE);
						rocks.push_back(rock);
					}
					posX++;
				}
			}
		}
	}
}