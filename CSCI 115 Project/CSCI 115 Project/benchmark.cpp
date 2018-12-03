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
using SortFunction = void (*)(std::vector<int>::iterator, std::vector<int>::iterator, unsigned long&);

struct BenchmarkInput {
	std::vector<int> unsorted;
	std::vector<int> sorted;
	std::vector<int> rsorted;
	std::vector<int> psorted_25;
	std::vector<int> psorted_50;
	std::vector<int> psorted_75;
	std::vector<int> few_unique;
	std::size_t input_size;
	std::size_t num_trials;

    BenchmarkInput(std::size_t input_size, std::size_t num_trials): 
		input_size(input_size), 
		num_trials(num_trials),
		unsorted(input_size, 0), 
		sorted(input_size, 0), 
		rsorted(input_size, 0), 
		psorted_25(input_size, 0),
		psorted_50(input_size, 0),
		psorted_75(input_size, 0),
		few_unique(input_size, 0) {}
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

struct RandomGenerator {
	int max_val;
	RandomGenerator(int max): max_val{max} {}
	int operator()() { return std::rand() % max_val; }
};

struct PSortedGenerator {
	std::size_t num_sorted;
	std::size_t curr;
	std::size_t max_val; 
	PSortedGenerator(std::size_t input_size, double ratio): 
		num_sorted{static_cast<std::size_t>(input_size * ratio)}, 
		curr{0},
		max_val{input_size} {}
	int operator()() { 
		return curr > num_sorted ? std::rand() % max_val : ++curr;
	}
};

// -----------------------------------------------------------
// Private helper methods
// -----------------------------------------------------------

static RuntimeRecord benchmark_one(SortFunction sort, BenchmarkInput const &input, bool use_ptei=true) {
    RuntimeRecord record;
	const std::size_t N = input.num_trials;

    for (auto i = 0; i < N; ++i) {
        if (i % (N / 10) == 0)
            std::cout << "." << std::flush;
        
        std::vector<int> unsorted    = input.unsorted;
        std::vector<int> sorted      = input.sorted;
		std::vector<int> rsorted     = input.rsorted;
		std::vector<int> psorted_25  = input.psorted_25;
		std::vector<int> psorted_50  = input.psorted_50;
		std::vector<int> psorted_75  = input.psorted_75;
		std::vector<int> few_unique  = input.few_unique;

        record.unsorted   += profile(sort, unsorted.begin(), unsorted.end() - (use_ptei ? 0 : 1), record.unsorted_count);
		record.sorted     += profile(sort, sorted.begin(), sorted.end() - (use_ptei ? 0 : 1), record.sorted_count);
		record.rsorted    += profile(sort, rsorted.begin(),  rsorted.end() - (use_ptei ? 0 : 1), record.rsorted_count);
		record.psorted_25 += profile(sort, psorted_25.begin(), psorted_25.end() - (use_ptei ? 0 : 1), record.psorted_25_count);;
		record.psorted_50 += profile(sort, psorted_50.begin(), psorted_50.end() - (use_ptei ? 0 : 1), record.psorted_50_count);;
		record.psorted_75 += profile(sort, psorted_75.begin(), psorted_75.end() - (use_ptei ? 0 : 1), record.psorted_75_count);;
		record.few_unique += profile(sort, few_unique.begin(), few_unique.end() - (use_ptei ? 0 : 1), record.few_unique_count);;
    }

	record.unsorted   = microseconds(record.unsorted.count() / N);
	record.sorted     = microseconds(record.sorted.count() / N);;
	record.rsorted    = microseconds(record.rsorted.count() / N);;
	record.psorted_25 = microseconds(record.psorted_25.count() / N);;
	record.psorted_50 = microseconds(record.psorted_50.count() / N);;
	record.psorted_75 = microseconds(record.psorted_75.count() / N);;
	record.few_unique = microseconds(record.few_unique.count() / N);

	record.unsorted_count   = (record.unsorted_count / (unsigned long)N);
	record.sorted_count     = (record.sorted_count / (unsigned long)N);;
	record.rsorted_count    = (record.rsorted_count / (unsigned long)N);;
	record.psorted_25_count = (record.psorted_25_count / (unsigned long)N);
	record.psorted_50_count = (record.psorted_50_count / (unsigned long)N);
	record.psorted_75_count = (record.psorted_75_count / (unsigned long)N);
	record.few_unique_count	= (record.few_unique_count / (unsigned long)N);

    return record;
}

// -----------------------------------------------------------
// Public API
// -----------------------------------------------------------

BenchmarkResults benchmark(std::size_t input_size, std::size_t num_trials) {
    BenchmarkInput input(input_size, num_trials);
	BenchmarkResults results;

	std::generate(input.unsorted.begin(),  input.unsorted.end(), RandomGenerator(input_size));
	std::generate(input.sorted.begin(),  input.sorted.end(),  ForwardGenerator());
	std::generate(input.rsorted.begin(), input.rsorted.end(), BackwardsGenerator(input_size));
	std::generate(input.psorted_25.begin(), input.psorted_25.end(), PSortedGenerator(input_size, 0.25));
	std::generate(input.psorted_50.begin(), input.psorted_50.end(), PSortedGenerator(input_size, 0.50));
	std::generate(input.psorted_75.begin(), input.psorted_75.end(), PSortedGenerator(input_size, 0.75));
	std::generate(input.few_unique.begin(), input.few_unique.end(), RandomGenerator(10));

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
	std::cout << "Quick Sort";
    results.quick_sort = benchmark_one(quick_sort, input, false);
	std::cout << "done" << std::endl;	

	// Hoare Quick Sort
	std::cout << "Hoare Quick Sort";
    results.hoare_quick_sort = benchmark_one(hoare_quick_sort, input, false);
	std::cout << "done" << std::endl;	

	// Randomized Quick Sort
	std::cout << "Randomized Quick Sort";
    results.randomized_quick_sort = benchmark_one(randomized_quick_sort, input, false);
	std::cout << "done" << std::endl;	

	// Heap Sort
	std::cout << "Heap Sort";
    results.heap_sort = benchmark_one(heap_sort, input);
	std::cout << "done" << std::endl;

	return results;
}