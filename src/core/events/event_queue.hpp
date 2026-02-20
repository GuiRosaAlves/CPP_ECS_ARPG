#pragma once
#include <variant>
#include <vector>
#include "core/events/events.hpp"

using GameEvent = std::variant<DamageEvent, CastSkillEvent, ApplyBuffEvent>;

class EventQueue
{
public:
    void push(GameEvent e) { events_.push_back(std::move(e)); }
    const std::vector<GameEvent> &events() const { return events_; }
    void clear() { events_.clear(); }

private:
    std::vector<GameEvent> events_;
};
