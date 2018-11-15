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
 *              sorted, such as the iterator returnd by std::vector::begin.
 * @peram end   iterator referring to the past-the-end element in the range to
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
 *              sorted, such as the iterator returnd by std::vector::begin.
 * @peram end   iterator referring to the past-the-end element in the range to
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
 *              sorted, such as the iterator returnd by std::vector::begin.
 * @peram end   iterator referring to the past-the-end element in the range to
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

#endif