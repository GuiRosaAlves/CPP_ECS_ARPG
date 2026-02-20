#pragma once
#include "core/state/game_state.hpp"
#include "engine/systems/systems.hpp"
#include "engine/resolvers/combat_resolver.hpp"

namespace engine
{
    inline void tick(GameState &gs)
    {
        systems::skill_system(gs);
        systems::buff_system(gs);

        resolvers::combat_resolver(gs);

        gs.events.clear();
    }
}
