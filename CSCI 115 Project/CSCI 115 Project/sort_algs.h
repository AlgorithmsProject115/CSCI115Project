#ifndef SORT_ALGS_H
#define SORT_ALGS_H

#include <vector>

template <typename RandomAccessIterator>
void exch(RandomAccessIterator i, RandomAccessIterator j) {
    auto tmp = *i;
    *i = *j;
    *j = tmp;
}

template <typename T>
void swap(std::vector<T> vec[], int i, int j)
{
    T temp = (*vec)[i];
    (*vec)[i] = (*vec)[j];
    (*vec)[j] = temp;
}

/**
 * Sorts the elements in the range [begin, end) in ascending order. 
 * The order of equal elements is not guaranteed to be preserved.
 * Iterators must meet the requirements of ValueSwappable. The type of
 * dereferenced RandomAccessIterator must be comparable with the < operator. 
 * 
 * @param begin iterator pointing to the first element in the range to be
 *              sorted, such as the iterator returned by std::vector::begin.
 * @param end   iterator referring to the past-the-end element in the range to
 *              be sorted, such as the iterator returned by std::vector::end.
 */ 
template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator begin, RandomAccessIterator end) {
    if (begin == end) return;

    for (auto i = begin + 1; i < end; ++i) {
        auto key = *i;
        auto j = i - 1;
        while (j >= begin && key < *j) {
            *(j + 1) = *j;
            --j;
        }
        *(j + 1) = key;
    }
}

/**
 * Sorts the elements in the range [begin, end) in ascending order. 
 * The order of equal elements is not guaranteed to be preserved.
 * Iterators must meet the requirements of ValueSwappable. The type of
 * dereferenced RandomAccessIterator must be comparable with the < operator. 
 * 
 * @param begin iterator pointing to the first element in the range to be
 *              sorted, such as the iterator returned by std::vector::begin.
 * @param end   iterator referring to the past-the-end element in the range to
 *              be sorted, such as the iterator returned by std::vector::end.
 */ 
template <typename RandomAccessIterator>
void selection_sort(RandomAccessIterator begin, RandomAccessIterator end) {
    if (begin == end) return;

    for (auto i = begin; i < end - 1; ++i) {
        auto min = i;
        for (auto j = i + 1; j < end; ++j) {
            if (*j < *min) {
                min = j;
            }
        }
        exch(i, min);
    }
}

/**
 * Sorts the elements in the range [begin, end) in ascending order. 
 * The order of equal elements is not guaranteed to be preserved.
 * Iterators must meet the requirements of ValueSwappable. The type of
 * dereferenced RandomAccessIterator must be comparable with the < operator. 
 * 
 * @param begin iterator pointing to the first element in the range to be
 *              sorted, such as the iterator returned by std::vector::begin.
 * @param end   iterator referring to the past-the-end element in the range to
 *              be sorted, such as the iterator returned by std::vector::end.
 */ 
template <typename RandomAccessIterator>
void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end) {
    if (begin == end) return;

    bool didSwap = false;

    for (auto i = end - 1; i > begin; --i) {
        for (auto j = begin; j < i; ++j) {
            if (*(j + 1) < *j) {
                exch(j, j + 1);
                didSwap = true;
            }
        }
        if (!didSwap) return;
    }
}

/**
 * Merges the two contiguous, pre-sorted ranges defined by [leftBegin, mid)
 * and [mid, rightEnd) guaranteeing that [leftBegin, rightEnd) is sorted in
 * ascending order
 * @param leftBegin iterator pointing to the first element of the 'left' range
 *              to be merged.
 * @param mid   iterator pointing to the mid-point of the combined 'left' and
 *              'right' ranges which is the past-the-end element for the 'left'
 *              range as well as the first element of the 'right' range.
 * @param rightEnd iterator pointing tothe past-the-end element for the 'right'
 *              range.
 */ 
template <typename RandomAccessIterator>
void merge_halves(RandomAccessIterator leftBegin, RandomAccessIterator mid, RandomAccessIterator rightEnd)
{
    // Prepare temporary vector and left/right pointers
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
    std::vector<value_type> temp;
    auto left = leftBegin;
    auto right = mid;

    // Compare left and right until either is exhausted
    while(left < mid && right < rightEnd)
    {
        temp.push_back(*left < *right ? *(left++) : *(right++));
    }

    // Add any remaining elements
    while(left < mid)
    {
        temp.push_back(*(left++));
    }
    while(right < rightEnd)
    {
        temp.push_back(*(right++));
    }

    // Copy temp into our original
    for(int i = 0; i < temp.size(); i++)
    {
        *(leftBegin + i) = temp[i];
    }
}

/**
 * Sorts the elements in the range [begin, end) in ascending order. 
 * The order of equal elements is not guaranteed to be preserved.
 * Iterator must meet the requirements of ValueSwappable . The type 
 * of dereferenced RandomAccessIterator must be comparable with the
 *  < operator. 
 * 
 * @param begin iterator pointing to the first element in the range to be
 *              sorted, such as the iterator returned by std::vector::begin.
 * @param end   iterator referring to the past-the-end element in the range to
 *              be sorted, such as the iterator returned by std::vector::end.
 */ 
template <typename RandomAccessIterator>
void merge_sort(RandomAccessIterator begin, RandomAccessIterator end)
{
    auto size = end - begin;
    if (size < 2) return;

    auto mid = begin + (size / 2);

    // use recursion to sort each half
    merge_sort(begin, mid);
    merge_sort(mid, end);

    // merge the two sorted halves
    merge_halves(begin, mid, end);
}


/**
 * Pivots the range of vec [low, high] on the value of the
 * high index so that all indices lower than the pivot have
 * smaller values than pivot and all indices greater than
 * pivot have larger values than pivot.  Returns the index
 * of pivot after sorting.
 * 
 * @param vec pointer to vector<T> to be sorted.
 * 
 * @param low first index of range
 * 
 * @param high last index of range
 */ 
#include <iostream>
template <typename RandomAccessIterator>
RandomAccessIterator partition(RandomAccessIterator lo, RandomAccessIterator hi) 
{
    RandomAccessIterator i = lo;
    RandomAccessIterator j = hi + 1;
    auto pivot = *lo;

    while (true)
    {
        while (*(++i) < pivot) if (i == hi) break;
        while (pivot < *(--j)) if (j == lo) break;
        if (i >= j) break;
        exch(i, j);
    }
    exch(lo, j);
    return j;
}

/**
 * Sorts the elements in the vector in ascending order. 
 * T must be comparable with the < operator. 
 * 
 * @param vec pointer to vector<T> to be sorted.
 * 
 * @param low first index
 * 
 * @param high last index
 */ 
template <typename RandomAccessIterator>
void quick_sort(RandomAccessIterator low, RandomAccessIterator high)
{
    if (high <= low) return;  
    
    RandomAccessIterator p = partition(low, high);

    // Quick sort on left and right of partition
    quick_sort(low, p);
    quick_sort(std::next(p), high);
}

/**
 * Heapifies the subtree starting at i with heapsize n
 * 
 * @param vec pointer to vector<T> backing heap.
 * 
 * @param i index of subtree
 * 
 * @param n size of heap
 */ 
template <typename T>
void heapify(std::vector<T> vec[], int i, int n)
{
    // Get left and right child based on 0-index
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    int largest = i;

    if(l <= n && (*vec)[l] > (*vec)[largest]) largest = l;
    if(r <= n && (*vec)[r] > (*vec)[largest]) largest = r;

    if(largest != i)
    {
        // swap the values at i and largest, then restore heap invariant.
        swap(vec, i, largest);
        heapify(vec, largest, n);
    }
}

/**
 * Sorts the elements in the vector in ascending order. 
 * T must be comparable with the < operator. 
 * 
 * @param vec pointer to vector<T> to be sorted.
 */ 
template <typename T>
void heap_sort(std::vector<T> vec[])
{
    int heapSize = (*vec).size();
    int firstParent = (heapSize / 2) - 1;

    // Build the heap
    for(int i = firstParent; i >= 0; i--) heapify(vec, i, heapSize - 1);

    for(int i = heapSize - 1; i > 0; i--)
    {
        swap(vec, 0, i);
        heapify(vec, 0, i-1);
    }
}

#endif