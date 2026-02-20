#pragma once
#include <cstdint>

using EntityId = std::uint32_t;
static constexpr EntityId kInvalidEntity = 0;

struct Entity
{
    EntityId id{kInvalidEntity};
    constexpr bool valid() const { return id != kInvalidEntity; }
};
