#include <catch2/catch_test_macros.hpp>
#include "core/events/event_queue.hpp"

TEST_CASE("EventQueue: push stores the events, clear removes them")
{
    EventQueue q;
    REQUIRE(q.events().empty());

    q.push(DamageEvent{1, 2, 10});
    q.push(ApplyBuffEvent{2, 5, 3});

    REQUIRE(q.events().size() == 2);

    q.clear();
    REQUIRE(q.events().empty());
}

TEST_CASE("Eventqueue: preserves insertion order of the events")
{
    EventQueue q;
    q.push(DamageEvent{1, 2, 10});
    q.push(DamageEvent{1, 2, 20});

    const auto *e0 = std::get_if<DamageEvent>(&q.events()[0]);
    const auto *e1 = std::get_if<DamageEvent>(&q.events()[1]);

    REQUIRE(e0 != nullptr);
    REQUIRE(e1 != nullptr);
    REQUIRE(e0->amount == 10);
    REQUIRE(e1->amount == 20);
}
