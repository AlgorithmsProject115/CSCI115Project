#include "catch.hpp"
#include "../profile.h"
#include <thread>
#include <chrono>
#include <functional>

using std::chrono::duration_cast;
using std::chrono::microseconds;
using std::chrono::milliseconds;

TEST_CASE( "profile" ) {

    SECTION( "Measures .001 second delay accurately." ) {
        auto delay = microseconds(1000);
        auto tolerance = delay.count() * 0.1; // Allowing 10% margin of error.
        auto duration = profile(
            [delay]() { std::this_thread::sleep_for(delay); }
        );
        auto diff = std::abs(duration - delay.count());
        REQUIRE(diff < tolerance);
    }

    SECTION( "Measures .01 second delay accurately." ) {
        auto delay = microseconds(10000);
        auto tolerance = delay.count() * 0.1; // Allowing 10% margin of error.
        auto duration = profile(
            [delay]() { std::this_thread::sleep_for(delay); }
        );
        auto diff = std::abs(duration - delay.count());
        REQUIRE(diff < tolerance);
    }

    SECTION( "Measures .1 second delay accurately." ) {
        auto delay = microseconds(100000);
        auto tolerance = delay.count() * 0.1; // Allowing 10% margin of error.
        auto duration = profile(
            [delay]() { std::this_thread::sleep_for(delay); }
        );
        auto diff = std::abs(duration - delay.count());
        REQUIRE(diff < tolerance);
    }

    SECTION( "Measures 1 second delay accurately." ) {
        auto delay = microseconds(1000000);
        auto tolerance = delay.count() * 0.1; // Allowing 10% margin of error.
        auto duration = profile(
            [delay]() { std::this_thread::sleep_for(delay); }
        );
        auto diff = std::abs(duration - delay.count());
        REQUIRE(diff < tolerance);
    }
}