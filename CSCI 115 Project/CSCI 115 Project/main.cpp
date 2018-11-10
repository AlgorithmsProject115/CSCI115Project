
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

----------------
Better Algorithm
----------------

Time Complexity O(NlogN)
	Assuming an input insensitive comparison based sorting algorithm, the time complexity for sort will be NlogN. 
	The for loop iterates over each element in the set, taking N comparisons, and BinarySearch takes logN comparisons N times. Thus, the result is NlogN
	Since the operations are not nested, this becomes O(NlogN + NlogN) = O(NlogN).

SumEqualsX (x)
	sort(set)
	for i <- all integers in set
		if( BinarySearch(x - i, set) )
			return true
	return false

*/