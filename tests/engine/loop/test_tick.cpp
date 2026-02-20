#include <catch2/catch_test_macros.hpp>
#include "core/state/game_state.hpp"
#include "engine/loop/tick.hpp"

TEST_CASE("Core: damage events are resolved and cleared on tick")
{
    GameState gs(1u);
    const EntityId a = gs.create_entity();
    const EntityId b = gs.create_entity();

    gs.events.push(DamageEvent{a, b, 15});
    REQUIRE(gs.events.events().size() == 1);

    engine::tick(gs);

    REQUIRE(gs.health[gs.index_of(b)].current == 85);
    REQUIRE(gs.events.events().empty());
}

TEST_CASE("Core: cooldown remaining are decremented on tick")
{
    GameState gs(1u);
    const EntityId e = gs.create_entity();

    auto &s = gs.skill[gs.index_of(e)];
    s.cooldownRemaining = 2;

    engine::tick(gs);
    REQUIRE(s.cooldownRemaining == 1);

    engine::tick(gs);
    REQUIRE(s.cooldownRemaining == 0);
}
