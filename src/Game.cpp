#include "Game.hpp"

Game::Game() :ns::App("NasNas Game Template", 720, 480) {
    ns::Config::debug = true;
    addDebugText("Hello World !", {20, 10});
}

void Game::onEvent(const sf::Event& event) {
    ns::App::onEvent(event);
}

void Game::update() {

}
