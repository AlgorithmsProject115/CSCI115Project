#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>
#include <cstddef>

struct RuntimeRecord {
	std::chrono::microseconds best_case;
	std::chrono::microseconds worst_case;
	std::chrono::microseconds avg_case;

	RuntimeRecord(): 
		best_case(std::chrono::microseconds::zero()), 
		worst_case(std::chrono::microseconds::zero()),
		avg_case(std::chrono::microseconds::zero()) {}
};

struct BenchmarkResults {
	RuntimeRecord insertion_sort;
	RuntimeRecord selection_sort;
	RuntimeRecord bubble_sort;
	RuntimeRecord merge_sort;
	RuntimeRecord quick_sort;
	RuntimeRecord heap_sort;
};

BenchmarkResults benchmark(std::size_t input_size, std::size_t num_trials);

#endif