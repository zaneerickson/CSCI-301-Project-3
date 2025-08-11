/*
 * CSCI 301 Project 3
 * Zane Erickson wm5766sl
 * Description of Problem:
 *   Program demonstrates the three required scenarios for ksmall:
 *     1) kth smallest in S1 (left partition)
 *     2) kth smallest is the pivot
 *     3) kth smallest in S2 (right partition)
 */
 
#ifndef KSMALL_H
#define KSMALL_H

#include <utility> //Used for std::swap

/*
 * @file kSmall.h
 * @brief Recursive selection (kth smallest) using first element as pivot.
 *
 * Constraints satisfied for the assignment:
 *  - Array is passed as a pointer (int*).
 *  - Uses a separate partition function that returns the pivot index.
 *  - No exceptions are thrown; caller must ensure 1 <= k <= (last-first+1).
 *  - Works with plain C-style arrays (no std::vector required).
 */

/*
 * @param a Pointer to the array (non-null)
 * @param first Starting index
 * @param last Ending index
 * @return The final index of the pivot
 */
int partition_first_pivot(int* a, int first, int last) {
    int pivot = a[first]; //Pivot = first element in array
    int i = first + 1; //i = second element in array
    for (int j = first + 1; j <= last; ++j) { //j initialized as second element in array
        if (a[j] < pivot) { //if value of a[j] is less than pivot number 
            std::swap(a[i], a[j]); //swap elements
            ++i; //increment i
        }
    }
    std::swap(a[first], a[i - 1]);
    return i - 1;
}

/*
 * @param a Pointer to the array
 * @param first Starting index (inclusive)
 * @param last Ending index (inclusive)
 * @param k 1-based order statistic within [first..last]
 * @return The kth smallest element's value
 */
int kSmall(int* a, int first, int last, int k) {
    if (first == last) {
        return a[first];
    }
    int p = partition_first_pivot(a, first, last);
    int rank = p - first + 1; //Pivot's 1-based rank in [first..last]
    if (k == rank) {
        return a[p];
    } else if (k < rank) {
        return kSmall(a, first, p - 1, k);
    } else {
        return kSmall(a, p + 1, last, k - rank);
    }
}

#endif // KSMALL_H
