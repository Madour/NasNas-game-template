#pragma once

#include <NasNas/Core.hpp>

class Game : public ns::App {
public:
    Game();
    void onEvent(const sf::Event& event) override;
    void update() override;
};
