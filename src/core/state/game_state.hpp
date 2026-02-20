#pragma once
#include <vector>
#include "core/state/entity.hpp"
#include "core/state/components.hpp"
#include "core/events/event_queue.hpp"
#include "core/util/rng.hpp"

struct GameState
{
    std::vector<Health> health;
    std::vector<Mana> mana;
    std::vector<Position> pos;
    std::vector<Skill> skill;
    std::vector<Buff> buff;

    EventQueue events;
    Rng rng;

    explicit GameState(std::uint32_t seed = 0x12345678u) : rng(seed) {}

    EntityId create_entity()
    {
        const auto idx = health.size();
        health.push_back({});
        mana.push_back({});
        pos.push_back({});
        skill.push_back({});
        buff.push_back({});
        return static_cast<EntityId>(idx + 1);
    }

    std::size_t index_of(EntityId id) const
    {
        return static_cast<std::size_t>(id - 1);
    }

    bool valid(EntityId id) const
    {
        if (id == kInvalidEntity)
            return false;
        const auto idx = index_of(id);
        return idx < health.size();
    }
};
