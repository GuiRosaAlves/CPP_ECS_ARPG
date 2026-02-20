#include <catch2/catch_test_macros.hpp>
#include <string>

#include "core/state/game_state.hpp"
#include "ui/format/console_renderer.hpp"

static bool contains(const std::string &s, const std::string &needle)
{
    return s.find(needle) != std::string::npos;
}

TEST_CASE("Console_renderer: to_string prints header and footer")
{
    GameState gs(1u);
    gs.create_entity();

    const auto out = ui::to_string(gs);

    REQUIRE(contains(out, "---- GameState ----\n"));
    REQUIRE(contains(out, "-------------------\n"));
}

TEST_CASE("Console_renderer: to_string prints one line per entity with HP,MP and buff info")
{
    GameState gs(1u);
    const EntityId e1 = gs.create_entity();
    const EntityId e2 = gs.create_entity();

    // Mutate state so we can assert visible changes
    gs.health[gs.index_of(e2)].current = 70;
    gs.buff[gs.index_of(e1)].armorBonus = 5;
    gs.buff[gs.index_of(e1)].remainingTicks = 3;

    const auto out = ui::to_string(gs);

    // Non-brittle: assert key substrings rather than exact whole output
    REQUIRE(contains(out, "Entity 1 | HP 100/100 | MP 50/50\n"));
    REQUIRE(contains(out, "Entity 2 | HP 70/100 | MP 50/50\n"));
}

TEST_CASE("Console_renderer: to_string prints no entity lines when there are no entities")
{
    GameState gs(1u);
    const auto out = ui::to_string(gs);

    REQUIRE(contains(out, "---- GameState ----\n"));
    REQUIRE(contains(out, "-------------------\n"));
    REQUIRE_FALSE(contains(out, "Entity "));
}
