#include <catch2/catch_test_macros.hpp>
#include <iostream>

TEST_CASE("Hello World!")
{
    std::cout << "Running Test...\n";

    const bool it_just_works = true;
    REQUIRE(it_just_works);

    std::cout << "Hello World!\n";
}
