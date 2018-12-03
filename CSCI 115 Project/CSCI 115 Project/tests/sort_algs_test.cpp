#include "catch.hpp"
#include "../sort_algs.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

// -------------------------------------------------------------
// Insertion-Sort test cases
// -------------------------------------------------------------
TEST_CASE( "insertion sort" ) {

    SECTION( "sorts empty vector" ) {
        std::vector<int> vec;
        unsigned long count = 0;
        insertion_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count == 0);
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        unsigned long count = 0;
        insertion_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count > 0);
    }

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long count = 0;
        insertion_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        unsigned long count = 0;
        insertion_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec = {"c", "f", "a", "g", "e", "b", "d"};
        unsigned long count = 0;
        insertion_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }
}

// -------------------------------------------------------------
// Selection-Sort test cases
// -------------------------------------------------------------
TEST_CASE( "selection sort" ) {

    SECTION( "sorts empty vector" ) {
        std::vector<int> vec;
        unsigned long count = 0;
        selection_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count == 0);
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        unsigned long count = 0;
        selection_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count > 0);
    }

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long count = 0;
        selection_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        unsigned long count = 0;
        selection_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec = {"c", "f", "a", "g", "e", "b", "d"};
        unsigned long count = 0;
        selection_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }
}

// -------------------------------------------------------------
// Bubble-Sort test cases
// -------------------------------------------------------------
TEST_CASE( "bubble sort" ) {

    SECTION( "sorts empty vector" ) {
        std::vector<int> vec;
        unsigned long count = 0;
        bubble_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count == 0);
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        unsigned long count = 0;
        bubble_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count > 0);
    }

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long count = 0;
        bubble_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        unsigned long count = 0;
        bubble_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec = {"c", "f", "a", "g", "e", "b", "d"};
        unsigned long count = 0;
        bubble_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }
}

// -------------------------------------------------------------
// Merge-Sort test cases
// -------------------------------------------------------------
TEST_CASE( "merge sort" ) {

    SECTION( "sorts empty vector" ) {
        std::vector<int> vec;
        unsigned long count = 0;
        merge_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count == 0);
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        unsigned long count = 0;
        merge_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count > 0);
    }

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long count = 0;
        merge_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        unsigned long count = 0;
        merge_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec = {"c", "f", "a", "g", "e", "b", "d"};
        unsigned long count = 0;
        merge_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }
}

// -------------------------------------------------------------
// Quick-Sort test cases
// -------------------------------------------------------------
TEST_CASE( "quick sort" ) {

    SECTION( "sorts empty vector" ) {
        std::vector<int> vec;
        unsigned long count = 0;
        quick_sort(vec.begin(), vec.end(), count); // vec.begin() == vec.end() for empty vectors
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count == 0);
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        unsigned long count = 0;
        quick_sort(vec.begin(), vec.end() - 1, count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count > 0);
    }

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long count = 0;
        quick_sort(vec.begin(), vec.end() - 1, count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        unsigned long count = 0;
        quick_sort(vec.begin(), vec.end() - 1, count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec = {"c", "f", "a", "g", "e", "b", "d"};
        unsigned long count = 0;
        quick_sort(vec.begin(), vec.end() - 1, count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }
}

// -------------------------------------------------------------
// Quick-Sort using Hoare partitioning
// -------------------------------------------------------------
TEST_CASE( "quick sort using hoare partitioning" ) {

    SECTION( "sorts empty vector" ) {
        std::vector<int> vec;
        unsigned long count = 0;
        hoare_quick_sort(vec.begin(), vec.end(), count); // vec.begin() == vec.end() for empty vectors
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count == 0);
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        unsigned long count = 0;
        hoare_quick_sort(vec.begin(), vec.end() - 1, count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count > 0);
    }
    

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long count = 0;
        hoare_quick_sort(vec.begin(), vec.end() - 1, count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        unsigned long count = 0;
        hoare_quick_sort(vec.begin(), vec.end() - 1, count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec = {"c", "f", "a", "g", "e", "b", "d"};
        unsigned long count = 0;
        hoare_quick_sort(vec.begin(), vec.end() - 1, count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }
}

// -------------------------------------------------------------
// Quick-Sort using randomized partitioning
// -------------------------------------------------------------
TEST_CASE( "quick sort using randomized partitioning" ) {

    SECTION( "sorts empty vector" ) {
        std::vector<int> vec;
        unsigned long count = 0;
        randomized_quick_sort(vec.begin(), vec.end(), count); // vec.begin() == vec.end() for empty vectors
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count == 0);
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        unsigned long count = 0;
        randomized_quick_sort(vec.begin(), vec.end() - 1, count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count > 0);
    }

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long count = 0;
        randomized_quick_sort(vec.begin(), vec.end() - 1, count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        unsigned long count = 0;
        randomized_quick_sort(vec.begin(), vec.end() - 1, count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec = {"c", "f", "a", "g", "e", "b", "d"};
        unsigned long count = 0;
        randomized_quick_sort(vec.begin(), vec.end() - 1, count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }
}

// -------------------------------------------------------------
// Heap-Sort test cases
// -------------------------------------------------------------
TEST_CASE( "heap sort" ) {

    SECTION( "sorts empty vector" ) {
        std::vector<int> vec;
        unsigned long count = 0;
        heap_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count == 0);
    }

    SECTION( "sorts non-empty sorted vector" ) {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        unsigned long count = 0;
        heap_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        REQUIRE(count > 0);
    }

    SECTION( "sorts non-empty reverse sorted vector" ) {
        std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long count = 0;
        heap_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts non-empty unsorted vector" ) {
        std::vector<int> vec = {5, 1, 4, 2, 3, 9, 6, 8, 7, 10};
        unsigned long count = 0;
        heap_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }

    SECTION( "sorts vector of strings" ) {
        std::vector<std::string> vec = {"c", "f", "a", "g", "e", "b", "d"};
        unsigned long count = 0;
        heap_sort(vec.begin(), vec.end(), count);
        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
    }
}