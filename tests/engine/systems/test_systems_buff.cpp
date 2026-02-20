#include <catch2/catch_test_macros.hpp>
#include "core/state/game_state.hpp"
#include "engine/systems/systems.hpp"

TEST_CASE("Systems_buff: decrements remainingTicks and clears armorBonus at 0")
{
    GameState gs(1u);
    const EntityId e = gs.create_entity();
    auto &b = gs.buff[gs.index_of(e)];

    b.armorBonus = 7;
    b.remainingTicks = 2;

    systems::buff_system(gs);
    REQUIRE(b.remainingTicks == 1);
    REQUIRE(b.armorBonus == 7);

    systems::buff_system(gs);
    REQUIRE(b.remainingTicks == 0);
    REQUIRE(b.armorBonus == 0);

    systems::buff_system(gs);
    REQUIRE(b.remainingTicks == 0);
    REQUIRE(b.armorBonus == 0);
}
