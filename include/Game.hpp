#pragma once

#include <NasNas.h>

class Game : public ns::App {
public:
    Game();
    void onEvent(const sf::Event& event);
    void update();
};