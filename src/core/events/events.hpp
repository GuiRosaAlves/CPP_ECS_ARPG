#pragma once
#include <cstdint>
#include "core/state/entity.hpp"

struct DamageEvent
{
    EntityId source{kInvalidEntity};
    EntityId target{kInvalidEntity};
    int amount{0};
};

struct CastSkillEvent
{
    EntityId caster{kInvalidEntity};
    EntityId target{kInvalidEntity};
    std::uint32_t skillId{0};
};

struct ApplyBuffEvent
{
    EntityId target{kInvalidEntity};
    int armorBonus{0};
    int durationTicks{0};
};
