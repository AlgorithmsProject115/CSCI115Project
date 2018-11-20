#include "catch.hpp"
#include "../sort_algs.h"
#include <vector>
#include <string>
#include <algorithm>

// -------------------------------------------------------------
// Insertion-Sort test cases
// -------------------------------------------------------------
TEST_CASE( "insertion sort" ) {

    SECTION( "sorts empty vector" ) {
        std::vector<int> vec;
        insertion_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        insertion_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        insertion_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        insertion_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec = {"c", "f", "a", "g", "e", "b", "d"};
        insertion_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }
}

// -------------------------------------------------------------
// Selection-Sort test cases
// -------------------------------------------------------------
TEST_CASE( "selection sort" ) {

    SECTION( "sorts empty vector" ) {
        std::vector<int> vec;
        selection_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        selection_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        selection_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        selection_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec = {"c", "f", "a", "g", "e", "b", "d"};
        selection_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }
}

// -------------------------------------------------------------
// Bubble-Sort test cases
// -------------------------------------------------------------
TEST_CASE( "bubble sort" ) {

    SECTION( "sorts empty vector" ) {
        std::vector<int> vec;
        bubble_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        bubble_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        bubble_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        bubble_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec = {"c", "f", "a", "g", "e", "b", "d"};
        bubble_sort(vec.begin(), vec.end());
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }
}