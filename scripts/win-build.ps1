$ErrorActionPreference = "Stop"

cmake -S . -B out/build/msvc -G Ninja `
  -DGS_ENABLE_TESTS=ON `
  -DCMAKE_BUILD_TYPE=Release

cmake --build out/build/msvc