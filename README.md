# CPP_ECS_ARPG

A modern C++ Gameplay Framework built to demonstrate production-oriented architecture, gameplay systems design, and UI integration using an ECS approach.

---

## Overview

**CPP_ECS_ARPG** is a modular gameplay framework designed to simulate Action RPG (ARPG) mechanics using a custom Entity-Component-System (ECS) architecture.

The project exists to:

- Demonstrate strong knowledge of **modern C++**
- Showcase gameplay and UI system design
- Present clean architecture and test coverage
- Provide a portfolio-ready codebase aligned with Gameplay/UI Programmer roles

This repository emphasizes:

- Data-oriented design
- Clear system boundaries
- Deterministic update loops
- Automated testing
- Cross-platform build configuration (Windows validated)

---

## Architecture

The framework follows a layered architecture:

```
├── 📁 .github
│   └── 📁 workflows
│       └── ⚙️ ci.yml
├── 📁 src
│   ├── 📁 core
│   │   ├── 📁 events
│   │   │   ├── ⚡ event_queue.hpp
│   │   │   └── ⚡ events.hpp
│   │   ├── 📁 state
│   │   │   ├── ⚡ components.hpp
│   │   │   ├── ⚡ entity.hpp
│   │   │   └── ⚡ game_state.hpp
│   │   └── 📁 util
│   │       └── ⚡ rng.hpp
│   ├── 📁 engine
│   │   ├── 📁 loop
│   │   │   └── ⚡ tick.hpp
│   │   ├── 📁 resolvers
│   │   │   ├── ⚡ combat_resolver.cpp
│   │   │   └── ⚡ combat_resolver.hpp
│   │   └── 📁 systems
│   │       ├── ⚡ buff_system.cpp
│   │       ├── ⚡ skill_system.cpp
│   │       └── ⚡ systems.hpp
│   ├── 📁 game
│   ├── 📁 ui
│   │   ├── 📁 format
│   │   │   └── ⚡ console_renderer.hpp
│   │   └── 📁 renderers
│   │       └── ⚡ console_renderer.cpp
│   └── ⚡ main.cpp
├── 📁 tests
│   ├── 📁 core
│   │   ├── 📁 events
│   │   │   └── ⚡ test_event_queue.cpp
│   │   ├── 📁 state
│   │   │   ├── ⚡ test_entity.cpp
│   │   │   └── ⚡ test_game_state.cpp
│   │   └── 📁 util
│   │       └── ⚡ test_rng.cpp
│   ├── 📁 engine
│   │   ├── 📁 loop
│   │   │   └── ⚡ test_tick.cpp
│   │   ├── 📁 resolvers
│   │   │   └── ⚡ test_combat_resolver.cpp
│   │   └── 📁 systems
│   │       ├── ⚡ test_skill_auto_attack.cpp
│   │       ├── ⚡ test_systems_buff.cpp
│   │       └── ⚡ test_systems_skill.cpp
│   ├── 📁 ui
│   │   └── 📁 format
│   │       └── ⚡ test_console_renderer.cpp
│   ├── 📄 CMakeLists.txt
│   └── ⚡ test_hello.cpp
├── ⚙️ .gitignore
├── 📄 CMakeLists.txt
├── ⚙️ CMakePresets.json
├── 📝 README.md
└── ⚙️ vcpkg.json
```

### 1. Core

Contains gameplay domain logic.

- ECS implementation
- Components
- Systems (combat, skills, movement)
- Event dispatching
- Resolver logic (damage, stat calculation, etc.)

### 2. Engine

Provides execution layer:

- Game loop
- System orchestration
- State management

### 3. UI

Interface abstraction layer:

- UI state
- Presentation logic
- Interaction binding

### 4. Tests

Mirrors the `src/` structure.

- Unit tests per class
- System behavior tests
- UI validation tests

---

## ECS Design Rationale

The Entity-Component-System model was chosen because:

- Decouples behavior from identity
- Improves scalability
- Simplifies gameplay iteration

---

## Implemented Gameplay Features

- Entity creation & destruction
- Component registration
- System scheduler
- Event dispatch system
- Resolver pattern for combat logic
- Auto-Attack skill system
- Deterministic update cycle

---

## Build Instructions (Windows)

### Requirements

- CMake (≥ 3.25)
- Ninja
- MSVC (Visual Studio toolchain)
- vcpkg (for dependency management)

---

### Configure

```powershell
cmake -S . -B build/debug -G Ninja -DGS_ENABLE_TESTS=ON -DCMAKE_BUILD_TYPE=Debug
```

### Build

```powershell
cmake --build build/debug
```

### Run Tests

```powershell
ctest --test-dir build/debug --output-on-failure
```

---

### Cross-Platform Intent

Although currently only tested on Windows, the build system is configured to support Linux builds through:

- CMake presets
- Platform-agnostic code
- Compiler-independent patterns

---

### Testing Strategy

Testing is done with:

- Unit tests for each class
- System-level behavior tests
- Resolver validation
- UI behavior verification

CTest is used as the test runner.

Test directory mirrors production structure to ensure traceability.

---

### Design Principles

- Modern C++ (C++20 features where applicable)
- RAII enforcement
- Explicit ownership semantics
- Minimal dynamic allocation in hot paths
- Deterministic system updates

---

### Example: Auto Attack Skill

The Auto Attack system demonstrates:

- Skill component binding
- Damage resolution via resolver
- Event emission
- System-driven execution
- Testable isolated logic

It acts as a foundation for:

- Cooldown systems
- Buff/Debuff mechanics
- Status effects
- Animation hooks

---

### Roadmap

Planned expansions:

- Cooldown & resource systems
- Buff/debuff architecture
- Attribute scaling framework
- AI behavior system
- Input abstraction layer
- Expanded UI state synchronization
- Performance benchmarks

---

### Why This Project Exists

This project was developed to:

- Strengthen advanced C++ skills
- Demonstrate gameplay system design
- Show architecture planning capability
- Present automated testing discipline
- Align with Gameplay/UI development requirements

It is intended as a professional portfolio artifact.

---
