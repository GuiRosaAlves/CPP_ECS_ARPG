#include <sstream>
#include <iostream>
#include "core/state/game_state.hpp"
#include "ui/format/console_renderer.hpp"

namespace ui
{
    // TODO: entire buff system is still inactive and needs to be implemented
    static void append_entity(std::ostringstream &out, const GameState &gs, EntityId id)
    {
        if (!gs.valid(id))
            return;
        const auto idx = gs.index_of(id);
        const auto &hp = gs.health[idx];
        const auto &mp = gs.mana[idx];
        const auto &b = gs.buff[idx];

        out << "Entity " << id
            << " | HP " << hp.current << "/" << hp.max
            << " | MP " << mp.current << "/"
            << mp.max << "\n";
        // << " | ArmorBuff " << b.armorBonus
        // << " (" << b.remainingTicks << " ticks)\n";
    }

    std::string to_string(const GameState &gs)
    {
        std::ostringstream out;
        out << "---- GameState ----\n";
        for (EntityId id = 1; id <= static_cast<EntityId>(gs.health.size()); ++id)
        {
            append_entity(out, gs, id);
        }
        out << "-------------------\n";
        return out.str();
    }

    void render(const GameState &gs)
    {
        std::cout << to_string(gs);
    }
}
