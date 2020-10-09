#include "Game.hpp"

Game::Game() :ns::App("NasNas Game Template", 720, 480) {
	addDebugText<std::string>([](){return "World !";}, "Hello", {0, 0});
}

void Game::onEvent(const sf::Event& event) {
	if (event.type == sf::Event::Closed)
		getWindow().close();

	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Escape)
			getWindow().close();
	}
}

void Game::update() {

}
