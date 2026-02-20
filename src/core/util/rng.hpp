#pragma once
#include <cstdint>

class Rng
{
public:
    explicit Rng(std::uint32_t seed = 0x12345678u) : state_(seed ? seed : 0x12345678u) {}

    // xorshift32
    std::uint32_t next_u32()
    {
        std::uint32_t x = state_;
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        state_ = x;
        return x;
    }

    // Range including the numbers themselves
    int range_int(int minInclusive, int maxInclusive)
    {
        if (maxInclusive < minInclusive)
            return minInclusive;
        const auto span = static_cast<std::uint32_t>(maxInclusive - minInclusive + 1);
        return minInclusive + static_cast<int>(next_u32() % span);
    }

private:
    std::uint32_t state_;
};
