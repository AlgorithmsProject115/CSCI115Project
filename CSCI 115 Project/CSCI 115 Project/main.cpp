#include "sort_algs.h"
#include "benchmark.h"
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>

//Part 2

/*
Brute Force Algorithm

Time Complexity: O(N^2)
	The first for loop iterates over all elements, this takes N time in the worst case (not found).
	The second for loop iterates over all elements for each each time the first loop does, resulting in N comparisons N times in the worst case (not found).
	The if statement results in N comparisons, this gives a total number of comparisons of N*(N+N) = 2N^2 = O(N^2)

SumEqualsX (x)
	for i <- all integers in set
		for j <- all integers in set
			if(i + j == x)
				return true
	return false
*/

/**
* Searches list and finds if a pair adds up to val by checking each pair
* The type of dereferenced RandomAccessIterator must have the operator + defined 
* and meet the requirements of EqualityComparable and LessThanComparable.
*
* @param begin iterator pointing to the first element in the range such as 
*              the iterator returned by std::vector::begin.
*              
* @param end   iterator referring to the past-the-end element in the range such as 
*              the iterator returned by std::vector::end.
*      
* @param val  Type matching dereferenced iterator referring to value to be compared against
*/

template <typename RandomAccessIterator, typename T = typename std::remove_reference<decltype(*RandomAccessIterator().p)>::type>
bool brute_force_find(RandomAccessIterator begin, RandomAccessIterator end, T val) {
	for (auto i = begin; i < end; ++i) {
		for (auto j = i + 1; j < end; ++j) {
			if (*i + *j == val)
				return true;
		}
	}
	return false;
}
/*
U
U
U
U
U
U
Better Algorithm

Time Complexity: O(N)
	It takes O(N) steps amortized/with an effective hash function to insert N integers in a hash table.
	The for loop then iterates over N elements, and with an amortized worst case Search() cost of O(1), 
	the result of the entire algorithm is O(N+N*1) = O(N)

SumEqualsX (x)
	store set in hash table
	for i <- all integers in set
		if( Search(x - i, set) )
			return true
	return false

*/

/**
* Searches list and finds if a pair adds up to val by inserting
* into hash table and searching for matches. It must meet
* the requirements of EqualityComparable and LessThanComparable.
*
* @param begin iterator pointing to the first element in the range such as
*              the iterator returned by std::vector::begin.
*
* @param end   iterator referring to the past-the-end element in the range such as
*              the iterator returned by std::vector::end.
*
* @param val   Type matching dereferenced iterator referring to value to be compared against
*/
template <typename RandomAccessIterator, typename T = typename std::remove_reference<decltype(*RandomAccessIterator().p)>::type>
bool hash_find(RandomAccessIterator begin, RandomAccessIterator end, T val) {

	std::unordered_map<T, RandomAccessIterator> hashtable;

	for (auto it = begin; it != end; ++it) {
		auto result = hashtable.find(val - *it);
		if (result != hashtable.end() && result->second != it) {						//modified to prevent double counting
			return true;
		}
		hashtable.insert({ {*it, it} });
	}
	return false;
}


// When RUN_UNIT_TESTS is defined, compiling the program will compile the
// unit tests. Then running the resulting executable will run the unit tests.
// Comment this line out to compile the normal program instead.
#ifdef RUN_UNIT_TESTS
#	define CATCH_CONFIG_MAIN
#	include "tests/catch.hpp"
#else

constexpr std::size_t NUM_TRIALS = 10;
constexpr std::size_t MAX_INPUT_SIZE = 65536;

int main() {
	std::srand(std::time(nullptr));

	std::ofstream unsorted_csv(  "benchmark_data/unsorted.csv",            std::ofstream::out);
	std::ofstream sorted_csv(    "benchmark_data/sorted.csv",              std::ofstream::out);
	std::ofstream reverse_csv(   "benchmark_data/reverse_sorted.csv",      std::ofstream::out);
	std::ofstream psorted25_csv( "benchmark_data/partially_sorted_25.csv", std::ofstream::out);
	std::ofstream psorted50_csv( "benchmark_data/partially_sorted_50.csv", std::ofstream::out);
	std::ofstream psorted75_csv( "benchmark_data/partially_sorted_75.csv", std::ofstream::out);
	std::ofstream few_unique_csv("benchmark_data/few_unique_10.csv",       std::ofstream::out);

	std::string headers = "N,insertion,selection,bubble,merge,quick,hoare-quick,randomized-quick,heap\n";

	unsorted_csv   << headers;
	sorted_csv     << headers;
	reverse_csv    << headers;
	psorted25_csv  << headers;
	psorted50_csv  << headers;
	psorted75_csv  << headers;
	few_unique_csv << headers;

	for (auto input_size = 1; input_size <= MAX_INPUT_SIZE; input_size *= 2) {
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Input size = " << input_size << ", # trials = " << NUM_TRIALS << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		
		BenchmarkResults results = benchmark(input_size, NUM_TRIALS);
		
		unsorted_csv << input_size                                     << ","
				     << results.insertion_sort.unsorted.count()        << ","
		 		     << results.selection_sort.unsorted.count()        << ","
				     << results.bubble_sort.unsorted.count()           << ","
				     << results.merge_sort.unsorted.count()            << ","
				     << results.quick_sort.unsorted.count()            << ","
					 << results.hoare_quick_sort.unsorted.count()      << ","
					 << results.randomized_quick_sort.unsorted.count() << ","      
				     << results.heap_sort.unsorted.count()             << "\n";

		
		sorted_csv << input_size                                   << ","
		           << results.insertion_sort.sorted.count()        << ","
		 		   << results.selection_sort.sorted.count()        << ","
				   << results.bubble_sort.sorted.count()           << ","
				   << results.merge_sort.sorted.count()            << ","
				   << results.quick_sort.sorted.count()            << ","
				   << results.hoare_quick_sort.sorted.count()      << ","
				   << results.randomized_quick_sort.sorted.count() << ","   
				   << results.heap_sort.sorted.count()             << "\n";

		reverse_csv << input_size                                    << ","
		            << results.insertion_sort.rsorted.count()        << ","
		 		    << results.selection_sort.rsorted.count()        << ","
				    << results.bubble_sort.rsorted.count()           << ","
				    << results.merge_sort.rsorted.count()            << ","
				    << results.quick_sort.rsorted.count()            << ","
					<< results.hoare_quick_sort.rsorted.count()      << ","
					<< results.randomized_quick_sort.rsorted.count() << ","   
				    << results.heap_sort.rsorted.count()             << "\n";

		psorted25_csv << input_size                                       << ","
		              << results.insertion_sort.psorted_25.count()        << ","
		 		      << results.selection_sort.psorted_25.count()        << ","
				      << results.bubble_sort.psorted_25.count()           << ","
				      << results.merge_sort.psorted_25.count()            << ","
				      << results.quick_sort.psorted_25.count()            << ","
					  << results.hoare_quick_sort.psorted_25.count()      << ","
					  << results.randomized_quick_sort.psorted_25.count() << ","   
				      << results.heap_sort.psorted_25.count()             << "\n";

		psorted50_csv << input_size                                       << ","
		              << results.insertion_sort.psorted_50.count()        << ","
		 		      << results.selection_sort.psorted_50.count()        << ","
				      << results.bubble_sort.psorted_50.count()           << ","
				      << results.merge_sort.psorted_50.count()            << ","
				      << results.quick_sort.psorted_50.count()            << ","
					  << results.hoare_quick_sort.psorted_50.count()      << ","
					  << results.randomized_quick_sort.psorted_50.count() << ","   
				      << results.heap_sort.psorted_50.count()             << "\n";

		psorted75_csv << input_size                                       << ","
		              << results.insertion_sort.psorted_75.count()        << ","
		 		      << results.selection_sort.psorted_75.count()        << ","
				      << results.bubble_sort.psorted_75.count()           << ","
				      << results.merge_sort.psorted_75.count()            << ","
				      << results.quick_sort.psorted_75.count()            << ","
					  << results.hoare_quick_sort.psorted_75.count()      << ","
					  << results.randomized_quick_sort.psorted_75.count() << ","   
				      << results.heap_sort.psorted_75.count()             << "\n";

		few_unique_csv << input_size                                       << ","
		               << results.insertion_sort.few_unique.count()        << ","
		 		       << results.selection_sort.few_unique.count()        << ","
				       << results.bubble_sort.few_unique.count()           << ","
				       << results.merge_sort.few_unique.count()            << ","
				       << results.quick_sort.few_unique.count()            << ","
					   << results.hoare_quick_sort.few_unique.count()      << ","
					   << results.randomized_quick_sort.few_unique.count() << ","   
				       << results.heap_sort.few_unique.count()             << "\n";

		std::cout << std::endl;
	}

	unsorted_csv.close();
	sorted_csv.close();
	reverse_csv.close();
	psorted25_csv.close();
	psorted50_csv.close();
	psorted75_csv.close();
	few_unique_csv.close();

	return 0;
}

#endif