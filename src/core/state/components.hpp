#pragma once
#include <cstdint>

// TODO: Skill definitions should be data-driven and not hardcoded
static constexpr std::uint32_t SKILL_AUTO_ATTACK = 1;

struct Health
{
    int current{100};
    int max{100};
};

struct Mana
{
    int current{50};
    int max{50};
};

struct Position
{
    int x{0};
    int y{0};
};

struct Buff
{
    int armorBonus{0};
    int remainingTicks{0};
};

struct Skill
{
    int manaCost{10};
    int cooldownTicks{5};
    int cooldownRemaining{0};
    int baseDamage{10};
};
