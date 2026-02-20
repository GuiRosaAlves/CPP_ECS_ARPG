#include <catch2/catch_test_macros.hpp>
#include "core/state/game_state.hpp"
#include "engine/systems/systems.hpp"
#include "engine/resolvers/combat_resolver.hpp"

TEST_CASE("Combat_resolver: DamageEvent resolves and does not allow negative hp")
{
    GameState gs(1u);
    const EntityId a = gs.create_entity();
    const EntityId b = gs.create_entity();

    REQUIRE(gs.health[gs.index_of(b)].current == 100);

    gs.events.push(DamageEvent{a, b, 15});
    resolvers::combat_resolver(gs);
    REQUIRE(gs.health[gs.index_of(b)].current == 85);

    gs.events.clear();
    gs.events.push(DamageEvent{a, b, 999});
    resolvers::combat_resolver(gs);
    REQUIRE(gs.health[gs.index_of(b)].current == 0);
}

TEST_CASE("Combat_resolver: invalid entities are ignored")
{
    GameState gs(1u);
    const EntityId a = gs.create_entity();

    gs.events.push(DamageEvent{a, 9999, 10});
    resolvers::combat_resolver(gs);

    REQUIRE(gs.health[gs.index_of(a)].current == 100);
}
