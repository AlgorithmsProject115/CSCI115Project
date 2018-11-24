#ifndef SORT_ALGS_H
#define SORT_ALGS_H

#include <vector>

template <typename GenericIterator>
void exch(GenericIterator i, GenericIterator j) {
    auto tmp = *i;
    *i = *j;
    *j = tmp;
}

/**
 * Sorts the elements in the range [begin, end) in ascending order. 
 * The order of equal elements is not guaranteed to be preserved.
 * GenericIterator must meet the requirements of ValueSwappable and
 * RandomAccessIterator. The type of dereferenced GenericIterator must
 * be comparable with the < operator. 
 * 
 * @param begin iterator pointing to the first element in the range to be
 *              sorted, such as the iterator returned by std::vector::begin.
 * @param end   iterator referring to the past-the-end element in the range to
 *              be sorted, such as the iterator returned by std::vector::end.
 */ 
template <typename GenericIterator>
void insertion_sort(GenericIterator begin, GenericIterator end) {
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
 * GenericIterator must meet the requirements of ValueSwappable and
 * RandomAccessIterator. The type of dereferenced GenericIterator must
 * be comparable with the < operator.
 * 
 * @param begin iterator pointing to the first element in the range to be
 *              sorted, such as the iterator returned by std::vector::begin.
 * @param end   iterator referring to the past-the-end element in the range to
 *              be sorted, such as the iterator returned by std::vector::end.
 */ 
template <typename GenericIterator>
void selection_sort(GenericIterator begin, GenericIterator end) {
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
 * GenericIterator must meet the requirements of ValueSwappable and
 * RandomAccessIterator. The type of dereferenced GenericIterator must
 * be comparable with the < operator. 
 * 
 * @param begin iterator pointing to the first element in the range to be
 *              sorted, such as the iterator returned by std::vector::begin.
 * @param end   iterator referring to the past-the-end element in the range to
 *              be sorted, such as the iterator returned by std::vector::end.
 */ 
template <typename GenericIterator>
void bubble_sort(GenericIterator begin, GenericIterator end) {
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
template <typename GenericIterator>
void merge_halves(GenericIterator leftBegin, GenericIterator mid, GenericIterator rightEnd)
{
    // Prepare temporary vector and left/right pointers
    typedef typename std::iterator_traits<GenericIterator>::value_type value_type;
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
 * GenericIterator must meet the requirements of ValueSwappable and
 * RandomAccessIterator. The type of dereferenced GenericIterator must
 * be comparable with the < operator. 
 * 
 * @param begin iterator pointing to the first element in the range to be
 *              sorted, such as the iterator returned by std::vector::begin.
 * @param end   iterator referring to the past-the-end element in the range to
 *              be sorted, such as the iterator returned by std::vector::end.
 */ 
template <typename GenericIterator>
void merge_sort(GenericIterator begin, GenericIterator end)
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

#endif