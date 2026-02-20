include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.4
)
FetchContent_MakeAvailable(Catch2)

add_executable(gs_tests
  core/state/test_entity.cpp
  core/state/test_game_state.cpp
  core/events/test_event_queue.cpp
  core/util/test_rng.cpp

  engine/systems/test_systems_skill.cpp
  engine/systems/test_systems_buff.cpp
  engine/systems/test_skill_auto_attack.cpp
  engine/resolvers/test_combat_resolver.cpp
  engine/loop/test_tick.cpp

  ui/format/test_console_renderer.cpp
)

target_include_directories(gs_tests PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/../src
)

target_link_libraries(gs_tests PRIVATE
  Catch2::Catch2WithMain
  gs_engine
  gs_ui
)

include(Catch)
catch_discover_tests(gs_tests)
