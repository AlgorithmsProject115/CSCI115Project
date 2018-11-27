#include "sort_algs.h"
#include <iostream>
#include <unordered_map>

// When RUN_UNIT_TESTS is defined, compiling the program will compile the
// unit tests. Then running the resulting executable will run the unit tests.
// Comment this line out to compile the normal program instead.
#define RUN_UNIT_TESTS

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
* GenericIterator must meet the requirements of RandomAccessIterator
* The type of dereferenced GenericIterator must have the operator + defined 
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

template <typename GenericIterator, typename T = typename std::remove_reference<decltype(*GenericIterator().p)>::type>
bool brute_force_find(GenericIterator begin, GenericIterator end, T val) {
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
* Searches list and finds if a pair adds up to val by inserting into hash
* table and searching for matches
* GenericIterator must meet the requirements of RandomAccessIterator
* The type of dereferenced GenericIterator must have the operator + defined
* and meet the requirements of EqualityComparable and LessThanComparable.
*
* @param begin iterator pointing to the first element in the range such as
*              the iterator returned by std::vector::begin.
*
* @param end   iterator referring to the past-the-end element in the range such as
*              the iterator returned by std::vector::end.
*
* @param val   Type matching dereferenced iterator referring to value to be compared against
*/
template <typename GenericIterator, typename T = typename std::remove_reference<decltype(*GenericIterator().p)>::type>
bool hash_find(GenericIterator begin, GenericIterator end, T val) {

	std::unordered_map<T,GenericIterator> hashtable;
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
/*
#ifdef RUN_UNIT_TESTS
#	define CATCH_CONFIG_MAIN
#	include "tests/catch.hpp"
#else
*/
int main() {
	//Basic testing
	//std::vector<int> a = { 1,2 };
	//std::vector<int> a = { 1,2, 1 };
	//std::cout << hash_find(a.begin(), a.end(), 2) << std::endl;
	system("pause");
	return 0;
}
//#endif
