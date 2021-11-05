#include "Game.hpp"

Game::Game() : ns::App("NasNas Game Template", {720, 480}) {
    // Create or initialize your drawables and game objects here

    // Create your scenes and cameras here

    // Add your game objects to your scenes here

    // Add your debug texts here
    ns::Settings::debug_mode = true;
    addDebugText("Hello World !", {20, 10});
}

void Game::onEvent(const sf::Event& event) {
    ns::App::onEvent(event);
    // Add your event handling here
}

void Game::update() {
    // Write your game logic here
}
