#include <catch2/catch_test_macros.hpp>

#include "core/state/game_state.hpp"
#include "core/events/events.hpp"
#include "engine/systems/systems.hpp"
#include "engine/resolvers/combat_resolver.hpp"

TEST_CASE("Skill_auto_attack: CastSkillEvent emits DamageEvent and reduces target hp")
{
    GameState gs(1u);
    const EntityId player = gs.create_entity();
    const EntityId enemy = gs.create_entity();

    {
        const auto idx = gs.index_of(player);
        gs.skill[idx].manaCost = 0;
        gs.skill[idx].cooldownTicks = 1;
        gs.skill[idx].cooldownRemaining = 0;
        gs.skill[idx].baseDamage = 15;
    }

    gs.events.push(CastSkillEvent{player, enemy, SKILL_AUTO_ATTACK});

    systems::skill_system(gs);
    resolvers::combat_resolver(gs);

    REQUIRE(gs.health[gs.index_of(enemy)].current == 85);
}

TEST_CASE("Skill_auto_attack: respects cooldown, no second use on the same tick")
{
    GameState gs(1u);
    const EntityId player = gs.create_entity();
    const EntityId enemy = gs.create_entity();

    {
        const auto idx = gs.index_of(player);
        gs.skill[idx].manaCost = 0;
        gs.skill[idx].cooldownTicks = 5;
        gs.skill[idx].cooldownRemaining = 0;
        gs.skill[idx].baseDamage = 15;
    }

    gs.events.push(CastSkillEvent{player, enemy, SKILL_AUTO_ATTACK});
    gs.events.push(CastSkillEvent{player, enemy, SKILL_AUTO_ATTACK});

    systems::skill_system(gs);
    resolvers::combat_resolver(gs);

    REQUIRE(gs.health[gs.index_of(enemy)].current == 85);
}
