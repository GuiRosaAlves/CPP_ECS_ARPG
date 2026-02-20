cmake_minimum_required(VERSION 3.24)

# ---------- Versioning ----------
set(GS_VERSION "0.0.0" CACHE STRING "CPP_ECS_ARPG version (e.g. 1.2.3 or 1.2.3+sha)")
project(CPP_ECS_ARPG VERSION ${GS_VERSION} LANGUAGES CXX)
message(STATUS "CPP_ECS_ARPG version: ${PROJECT_VERSION}")

# ---------- Build metadata ----------
set(GS_GIT_REF "" CACHE STRING "Git ref (e.g. refs/tags/v1.2.3)")
set(GS_GIT_SHA "" CACHE STRING "Git commit SHA")

configure_file(
  ${CMAKE_SOURCE_DIR}/src/core/version.hpp.in
  ${CMAKE_BINARY_DIR}/generated/gs/version.hpp
  @ONLY
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(GS_ENABLE_TESTS "Build tests" ON)

# Core is header-only for now
add_library(gs_core
  src/core/version.cpp
)
target_include_directories(gs_core PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_BINARY_DIR}/generated
)

# Engine
add_library(gs_engine
  src/engine/systems/skill_system.cpp
  src/engine/systems/buff_system.cpp
  src/engine/resolvers/combat_resolver.cpp
)
target_link_libraries(gs_engine PUBLIC gs_core)
target_include_directories(gs_engine PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_BINARY_DIR}/generated
)

# UI
add_library(gs_ui
  src/ui/renderers/console_renderer.cpp
)
target_link_libraries(gs_ui PUBLIC gs_core)
target_include_directories(gs_ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# App
add_executable(gs_app src/main.cpp)
target_link_libraries(gs_app PRIVATE gs_engine gs_ui)
target_include_directories(gs_app PRIVATE ${CMAKE_BINARY_DIR}/generated)

# Tests
if (GS_ENABLE_TESTS)
  include(CTest)
  enable_testing()
  add_subdirectory(tests)
endif()