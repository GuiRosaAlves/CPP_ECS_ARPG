cmake_minimum_required(VERSION 3.24)
project(GameplaySystems LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(GS_ENABLE_TESTS "Build tests" ON)

# Core is header-only for now
add_library(gs_core INTERFACE)
target_include_directories(gs_core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Engine: systems + resolvers are compiled
add_library(gs_engine
  src/engine/systems/skill_system.cpp
  src/engine/systems/buff_system.cpp
  src/engine/resolvers/combat_resolver.cpp
)
target_link_libraries(gs_engine PUBLIC gs_core)
target_include_directories(gs_engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# UI compiled
add_library(gs_ui
  src/ui/renderers/console_renderer.cpp
)
target_link_libraries(gs_ui PUBLIC gs_core)
target_include_directories(gs_ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# App
add_executable(gs_app src/main.cpp)
target_link_libraries(gs_app PRIVATE gs_engine gs_ui)

# Tests
if (GS_ENABLE_TESTS)
  include(CTest)
  enable_testing()
  add_subdirectory(tests)
endif()
