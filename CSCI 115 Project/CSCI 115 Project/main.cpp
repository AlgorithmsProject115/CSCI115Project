#include "sort_algs.h"

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

#ifdef RUN_UNIT_TESTS
#	define CATCH_CONFIG_MAIN
#	include "tests/catch.hpp"
#else
int main() {
	return 0;
}
#endif