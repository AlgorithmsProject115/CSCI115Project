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
        std::vector<int> vec1;
        std::vector<int> vec2;
        insertion_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        insertion_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec1 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        insertion_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec1 = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        insertion_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec1 = {"c", "f", "a", "g", "e", "b", "d"};
        std::vector<std::string> vec2 = {"a", "b", "c", "d", "e", "f", "g"};
        insertion_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }
}

// -------------------------------------------------------------
// Selection-Sort test cases
// -------------------------------------------------------------
TEST_CASE( "selection sort" ) {

    SECTION( "sorts empty vector" ) {
        std::vector<int> vec1;
        std::vector<int> vec2;
        selection_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        selection_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec1 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        selection_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec1 = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        selection_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec1 = {"c", "f", "a", "g", "e", "b", "d"};
        std::vector<std::string> vec2 = {"a", "b", "c", "d", "e", "f", "g"};
        selection_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }
}

// -------------------------------------------------------------
// Bubble-Sort test cases
// -------------------------------------------------------------
TEST_CASE( "bubble sort" ) {

    SECTION( "sorts empty vector" ) {
        std::vector<int> vec1;
        std::vector<int> vec2;
        bubble_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        bubble_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec1 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        bubble_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec1 = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        bubble_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec1 = {"c", "f", "a", "g", "e", "b", "d"};
        std::vector<std::string> vec2 = {"a", "b", "c", "d", "e", "f", "g"};
        bubble_sort(vec1.begin(), vec1.end());
        REQUIRE(std::equal(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
    }
}