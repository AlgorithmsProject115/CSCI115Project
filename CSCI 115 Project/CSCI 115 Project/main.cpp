#include "sort_algs.h"
#include <unordered_set>
#include <iostream>
#include <vector>
#include <sstream>
#include <time.h>

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

	std::unordered_set<T> hashtable;
	for (auto it = begin; it != end(); ++it) {
		hashtable.insert(*it);
	}

	for (auto it = begin; it != end(); ++it) {
		auto result = hashtable.find(val - *it);
		if (result != hashtable.end() && result != it) {						//modified to prevent double counting
			return true;
		}
	}
	return false;
}

#ifdef RUN_UNIT_TESTS
#	define CATCH_CONFIG_MAIN
#	include "tests/catch.hpp"
#else
enum Sort {insert, select, bubble, merge, quick, heap};
enum Display {second, cycle};

// Displays the sort options and handles user input
Sort sort_menu()
{
	std::string strInput;
	int input;
	
		std::cout << "Choose a sort:" << std::endl;
		std::cout << "\t0 - Insert" << std::endl;
		std::cout << "\t1 - Select" << std::endl;
		std::cout << "\t2 - Bubble" << std::endl;
		std::cout << "\t3 - Merge" << std::endl;
		std::cout << "\t4 - Quick" << std::endl;
		std::cout << "\t5 - Heap" << std::endl;
	{
		getline(std::cin, strInput);
		input = stoi(strInput);
	}
	while(input < 0 || input > 5);
	
	return static_cast<Sort>(input);
}

// Displays the time display menu and handles user input
Display display_menu()
{
	std::string strInput;
	int input;
	
		std::cout << "Choose format to display time:" << std::endl;
		std::cout << "\t0 - Seconds" << std::endl;
		std::cout << "\t1 - Cycles" << std::endl;
	{
		getline(std::cin, strInput);
		input = stoi(strInput);
	}
	while(input < 0 || input > 1);
	
	return static_cast<Display>(input);
}

// converts a space delimited list of integers into a new vector.
int make_test(std::string input, std::vector<int>* list)
{
	int n = 0;
	int num;
	std::istringstream iss(input);
	while(iss >> num)
	{
		(*list).push_back(num);
		n++;
	}
	return n;
}

// Prints the passed vector
void print_vector(std::vector<int>* v)
{
	std::cout << "n=" << (*v).size() << ": ";
	for(std::vector<int>::iterator i = (*v).begin(); i < (*v).end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

// Prints the time results as a pair
void print_result(int n, clock_t start, clock_t end, Display display)
{
	clock_t cycles = end - start;
	double seconds = ((double)cycles / CLOCKS_PER_SEC);
	std::cout << "(" << n << "," << ( display == second ? seconds : cycles) << ")" << std::endl;
}


int main() {
	Sort sort;
	Display timeDisplay;
	int n;
	clock_t start, end;

	// Ask the user for the type of sort to use
	sort = sort_menu();
	
	// Ask the user for time display preference
	timeDisplay = display_menu();

	// Ask the user for the sequence of numbers to sort and repeat until user quits
	std::cout << "Enter the sequence of integers to be sorted separated by spaces (enter \"q\" to quit):" << std::endl;
	std::string input;
	getline(std::cin, input);
	while(input.compare("q") != 0)
	{
		std::vector<int> testCase;
		n = make_test(input, &testCase);

		switch(sort)
		{
			case insert:
			{
				// insertion
				start = clock();
				insertion_sort(testCase.begin(), testCase.end());
				end = clock();
				break;
			}
			case select:
			{
				// selection
				start = clock();
				selection_sort(testCase.begin(), testCase.end());
				end = clock();
				break;
			}
			case bubble:
			{
				// bubble
				start = clock();
				bubble_sort(testCase.begin(), testCase.end());
				end = clock();
				break;
			}
			case merge:
			{
				// merge
				start = clock();
				merge_sort(testCase.begin(), testCase.end());
				end = clock();
				break;
			}
			case quick:
			{
				// quick
				// start = clock();
				// quick_sort(testCase.begin(), testCase.end());
				// end = clock();
				break;
			}
			case heap:
			{
				// heap
				// start = clock();
				// heap_sort(heapVect.begin(), heapVect.end());
				// end = clock();
				break;
			}
		}
		//print_vector(&testCase);
		print_result(n, start, end, timeDisplay);
		getline(std::cin, input);
	}
	
	system("pause");
	return 0;
}
#endif