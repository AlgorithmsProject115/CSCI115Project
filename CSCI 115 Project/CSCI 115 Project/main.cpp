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
	
	It takes O(N) steps amortized/with an effective hash function to insert N integers in a hash table.
	The for loop then iterates over N elements, and with an amortized worst case Search() cost of O(1), the result of the entire algorithm is O(N+N*1) = O(N)

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
		hashtable.insert({{*it, it}});
	}

	for (auto it = begin; it != end; ++it) {
		auto result = hashtable.find(val - *it);
		if (result != hashtable.end() && result->second != it) {						//modified to prevent double counting
			return true;
		}
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

	std::ofstream best_csv("benchmark_data/best_cast.csv", std::ofstream::out);
	std::ofstream worst_csv("benchmark_data/worst_case.csv", std::ofstream::out);
	std::ofstream avg_csv("benchmark_data/avg_case.csv", std::ofstream::out);

	best_csv << "N,insertion,selection,bubble,merge,quick,heap\n";
	worst_csv << "N,insertion,selection,bubble,merge,quick,heap\n";
	avg_csv << "N,insertion,selection,bubble,merge,quick,heap\n";

	for ( auto input_size = 1; input_size <= MAX_INPUT_SIZE; input_size *= 2) {
		std::cout << "------------------------------------------------------------" << std::endl;
		std::cout << "Input size = " << input_size << ", # trials = " << NUM_TRIALS << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		
		BenchmarkResults results = benchmark(input_size, NUM_TRIALS);
		
		best_csv << input_size                               << ","
				 << results.insertion_sort.best_case.count() << ","
		 		 << results.selection_sort.best_case.count() << ","
				 << results.bubble_sort.best_case.count()    << ","
				 << results.merge_sort.best_case.count()     << ","
				 << 0                                        << ","
				 << 0                                        << "\n";

		
		worst_csv << input_size                                << ","
		          << results.insertion_sort.worst_case.count() << ","
		 		  << results.selection_sort.worst_case.count() << ","
				  << results.bubble_sort.worst_case.count()    << ","
				  << results.merge_sort.worst_case.count()     << ","
				  << 0                                         << ","
				  << 0                                         << "\n";

		
		avg_csv << input_size                              << ","
		        << results.insertion_sort.avg_case.count() << ","
		 		<< results.selection_sort.avg_case.count() << ","
				<< results.bubble_sort.avg_case.count()    << ","
				<< results.merge_sort.avg_case.count()     << ","
				<< 0                                       << ","
				<< 0                                       << "\n";

		std::cout << std::endl;
	}

	best_csv.close();
	worst_csv.close();
	avg_csv.close();

	return 0;
}

#endif
