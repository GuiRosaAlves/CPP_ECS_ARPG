#include "core/state/game_state.hpp"
#include "core/events/events.hpp"

namespace resolvers
{
    static int clamp_min(int v, int minv) { return (v < minv) ? minv : v; }

    void combat_resolver(GameState &gs)
    {
        for (const auto &ev : gs.events.events())
        {
            if (const auto *dmg = std::get_if<DamageEvent>(&ev))
            {
                if (!gs.valid(dmg->target))
                    continue;
                auto &hp = gs.health[gs.index_of(dmg->target)];
                hp.current = clamp_min(hp.current - dmg->amount, 0);
            }
        }
    }
}
