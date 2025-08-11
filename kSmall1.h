
#ifndef KSMALL_H
#define KSMALL_H


/*
 * @file kSmall.h
 * @brief Recursive selection (Quickselect-like) for the kth smallest element.
 *
 * Implements the algorithm described in lecture (kSmall) using the *first*
 * element as the pivot and a dedicated partition function.
 *
 * All array parameters are passed as pointers, per the assignment requirement.
 */

/*
 * @brief Partition subarray a[first..last] using the first element as pivot.
 *
 * Elements strictly less than the pivot are moved before it; elements greater
 * than or equal to the pivot remain after it. The pivot is placed at its final
 * sorted position, and that index is returned.
 *
 * This version safely handles the case where S1 (elements < pivot) is empty:
 * in that case the final swap becomes a no-op, avoiding out-of-bounds access.
 *
 * @param a Pointer to the array (must be non-null)
 * @param first Starting index (inclusive)
 * @param last Ending index (inclusive)
 * @return The final index of the pivot
 */
inline int partition_first_pivot(int* a, int first, int last) {
    int pivot = a[first];
    int i = first + 1;
    for (int j = first + 1; j <= last; ++j) {
        if (a[j] < pivot) {
            std::swap(a[i], a[j]);
            ++i;
        }
    }
    std::swap(a[first], a[i - 1]);
    return i - 1;
}

/*
 * @brief Return the kth smallest element (1-based k) within a[first..last].
 *
 * Uses recursion to compare k against the pivot's rank and recurs only into
 * the relevant side, giving expected linear time on average.
 *
 * @param a Pointer to the array
 * @param first Starting index (inclusive)
 * @param last Ending index (inclusive)
 * @param k 1-based order statistic within [first..last]
 * @return The kth smallest element's value
 * @throws std::out_of_range if k < 1 or k > (last-first+1)
 */
inline int kSmall(int* a, int first, int last, int k) {
    int n = last - first + 1;
    if (k < 1 || k > n) {
        throw std::out_of_range("k out of range for current subarray");
    }

    if (first == last) {
        return a[first];
    }

    int p = partition_first_pivot(a, first, last);
    int rank = p - first + 1; // pivot's 1-based rank in [first..last]
    if (k == rank) {
        return a[p];
    } else if (k < rank) {
        return kSmall(a, first, p - 1, k);
    } else {
        return kSmall(a, p + 1, last, k - rank);
    }
}

#endif // KSMALL_H
