#include <iostream>
#include <limits>
#include <string_view>
#include "core/version.hpp"
#include "core/state/game_state.hpp"
#include "engine/loop/tick.hpp"
#include "ui/format/console_renderer.hpp"
#include "core/events/events.hpp"

int main(int argc, const char **argv)
{
  // Check version
  for (int i = 1; i < argc; ++i)
  {
    std::string_view arg = argv[i];
    if (arg == "--version" || arg == "-v")
    {
      std::cout << "CPP_ECS_ARPG " << gs::core::build::version()
                << " (" << gs::core::build::git_sha() << ")\n";
      return 0;
    }
  }

  GameState gs(0xC0FFEEu);

  const EntityId player = gs.create_entity();
  const EntityId enemy = gs.create_entity();

  // TODO: make this more data-driven by searching from a db or file
  // Configure player AA skill parameters
  {
    const auto idx = gs.index_of(player);
    gs.skill[idx].manaCost = 0;
    gs.skill[idx].cooldownTicks = 1;
    gs.skill[idx].baseDamage = 15;
  }

  gs.events.push(CastSkillEvent{player, enemy, SKILL_AUTO_ATTACK});
  engine::tick(gs);
  ui::render(gs);

  gs.events.push(CastSkillEvent{player, enemy, SKILL_AUTO_ATTACK});
  engine::tick(gs);
  ui::render(gs);

  std::cout << "Press Enter to exit...";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
