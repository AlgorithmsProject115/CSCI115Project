#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>
#include <cstddef>

struct RuntimeRecord {
	std::chrono::microseconds unsorted;
	std::chrono::microseconds sorted;
	std::chrono::microseconds rsorted;
	std::chrono::microseconds psorted_25;
	std::chrono::microseconds psorted_50;
	std::chrono::microseconds psorted_75;
	std::chrono::microseconds few_unique;

	unsigned long unsorted_count;
	unsigned long sorted_count;
	unsigned long rsorted_count;
	unsigned long psorted_25_count;
	unsigned long psorted_50_count;
	unsigned long psorted_75_count;
	unsigned long few_unique_count;

	RuntimeRecord(): 
		unsorted(std::chrono::microseconds::zero()), 
		sorted(std::chrono::microseconds::zero()), 
		rsorted(std::chrono::microseconds::zero()), 
		psorted_25(std::chrono::microseconds::zero()), 
		psorted_50(std::chrono::microseconds::zero()), 
		psorted_75(std::chrono::microseconds::zero()), 
		few_unique(std::chrono::microseconds::zero()),
		unsorted_count(0),
		sorted_count(0),
		rsorted_count(0),
		psorted_25_count(0),
		psorted_50_count(0),
		psorted_75_count(0),
		few_unique_count(0) {}
};

struct BenchmarkResults {
	RuntimeRecord insertion_sort;
	RuntimeRecord selection_sort;
	RuntimeRecord bubble_sort;
	RuntimeRecord merge_sort;
	RuntimeRecord quick_sort;
	RuntimeRecord hoare_quick_sort;
	RuntimeRecord randomized_quick_sort;
	RuntimeRecord heap_sort;
};

BenchmarkResults benchmark(std::size_t input_size, std::size_t num_trials);

#endif