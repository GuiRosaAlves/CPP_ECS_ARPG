#include "engine/systems/systems.hpp"

namespace systems
{
    // TODO: entire buff system is still inactive and needs to be implemented
    void buff_system(GameState &gs)
    {
        for (std::size_t i = 0; i < gs.buff.size(); ++i)
        {
            auto &b = gs.buff[i];
            if (b.remainingTicks > 0)
                b.remainingTicks--;
            if (b.remainingTicks == 0)
                b.armorBonus = 0;
        }
    }
}
