#pragma once
#include <string>

struct GameState;

namespace ui
{
    std::string to_string(const GameState &gs);
    void render(const GameState &gs);
}
