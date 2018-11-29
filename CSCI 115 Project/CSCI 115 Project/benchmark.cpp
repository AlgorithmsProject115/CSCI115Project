#include "benchmark.h"
#include "profile.h"
#include "sort_algs.h"
#include <iostream>
#include <algorithm>

// -----------------------------------------------------------
// Data type definitions
// -----------------------------------------------------------

using std::chrono::duration_cast;
using std::chrono::microseconds;
using SortFunction = void (*)(std::vector<int>::iterator, std::vector<int>::iterator);

struct BenchmarkInput {
	std::vector<int> sorted;
	std::vector<int> reverse;
	std::vector<int> random;
	std::size_t input_size;
	std::size_t num_trials;

    BenchmarkInput(std::size_t input_size, std::size_t num_trials): 
		input_size(input_size), 
		num_trials(num_trials), 
		sorted(input_size, 0), 
		reverse(input_size, 0), 
		random(input_size, 0) {}
};

struct ForwardGenerator {
	int curr;
	ForwardGenerator(): curr{0} {}
	int operator()() { return curr++; }
};

struct BackwardsGenerator {
	int curr;
	BackwardsGenerator(int max): curr{max} {}
	int operator()() { return curr--; }
};

// -----------------------------------------------------------
// Private helper methods
// -----------------------------------------------------------

static RuntimeRecord benchmark_one(SortFunction sort, BenchmarkInput const &input) {
    RuntimeRecord record;
	const std::size_t N = input.num_trials;

    for (auto i = 0; i < N; ++i) {
        if (i % (N / 10) == 0)
            std::cout << "." << std::flush;
        
        std::vector<int> sorted  = input.sorted;
        std::vector<int> reverse = input.reverse;
		std::vector<int> random  = input.random;

        record.best_case  += profile(sort, sorted.begin(),  sorted.end());
		record.worst_case += profile(sort, reverse.begin(), reverse.end());
		record.avg_case   += profile(sort, random.begin(),  random.end());
    }

	record.best_case  = microseconds(record.best_case.count() / N);
	record.worst_case = microseconds(record.worst_case.count() / N);;
	record.avg_case   = microseconds(record.avg_case.count() / N);;

    return record;
}

// -----------------------------------------------------------
// Public API
// -----------------------------------------------------------

BenchmarkResults benchmark(std::size_t input_size, std::size_t num_trials) {
    BenchmarkInput input(input_size, num_trials);
	BenchmarkResults results;

	std::generate(input.sorted.begin(),  input.sorted.end(),  ForwardGenerator());
	std::generate(input.reverse.begin(), input.reverse.end(), BackwardsGenerator(input_size));
	std::generate(input.random.begin(),  input.random.end(),  [input_size]() { return std::rand() % input_size; });

	// Insertion Sort
	std::cout << "Insertion Sort";
    results.insertion_sort = benchmark_one(insertion_sort, input);
	std::cout << "done" << std::endl;	

	// Selection Sort
	std::cout << "Selection Sort";
    results.selection_sort = benchmark_one(selection_sort, input);
	std::cout << "done" << std::endl;	

	// Bubble Sort
	std::cout << "Bubble Sort";
    results.bubble_sort = benchmark_one(bubble_sort, input);
	std::cout << "done" << std::endl;	

	// Merge Sort
	std::cout << "Merge Sort";
    results.merge_sort = benchmark_one(merge_sort, input);
	std::cout << "done" << std::endl;	

	// Quick Sort

	// Heap Sort

	return results;
}