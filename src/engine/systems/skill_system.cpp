#include "engine/systems/systems.hpp"
#include <vector>
#include "core/events/events.hpp"

namespace systems
{
    void skill_system(GameState &gs)
    {
        // Tick cooldowns
        for (auto &s : gs.skill)
        {
            if (s.cooldownRemaining > 0)
                s.cooldownRemaining--;
        }

        // Cast Skill Events
        std::vector<CastSkillEvent> casts;
        casts.reserve(gs.events.events().size());
        for (const auto &ev : gs.events.events())
        {
            if (const auto *cast = std::get_if<CastSkillEvent>(&ev))
            {
                casts.push_back(*cast);
            }
        }
        // TODO: TRANSFORM THIS INTO A RESOLVER LATER, FOR NOW THIS IS FINE
        for (const auto &cast : casts)
        {
            if (!gs.valid(cast.caster) || !gs.valid(cast.target))
                continue;

            const auto casterIdx = gs.index_of(cast.caster);
            auto &casterMana = gs.mana[casterIdx];
            auto &casterSkill = gs.skill[casterIdx];

            if (cast.skillId == SKILL_AUTO_ATTACK)
            {
                // Validate cast
                if (casterSkill.cooldownRemaining > 0)
                    continue;
                if (casterMana.current < casterSkill.manaCost)
                    continue;

                // Spend resources
                casterMana.current -= casterSkill.manaCost;
                casterSkill.cooldownRemaining = casterSkill.cooldownTicks;

                // Emit damage
                gs.events.push(DamageEvent{
                    .source = cast.caster,
                    .target = cast.target,
                    .amount = casterSkill.baseDamage});
            }
        }
    }
}