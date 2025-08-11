
/*
 * CSCI 301 Project 3
 * Zane Erickson wm5766sl
 * Description of Problem:
 *   Program demonstrates the three required scenarios for ksmall:
 *     1) kth smallest in S1 (left partition)
 *     2) kth smallest is the pivot
 *     3) kth smallest in S2 (right partition)
 */

#include <iostream>
#include "kSmall.h"
using namespace std;

static void print(const int* a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i + 1 == n ? "" : " "); //prints (dynamic) array
    }
}

static void copyarr(const int* src, int* dst, int n) {
    for (int i = 0; i < n; ++i)
        dst[i] = src[i]; //Copies elements from old array to new array
}

int main() {

    int defaultarray[] = {4, 3, 1, 2, 7, 10}; //This is your base array
    const int n = 6; //Size of array

    //Case 1: kth is in S1 (left partition)
    {
        int* a = new int[n]; //Pointer to a dynamically created array's first value
        copyarr(defaultarray, a, n);
        int k = 2; // 2nd smallest = 3 -> in S1 relative to pivot=6
        cout << "[S1 case] default array: ";
        print(defaultarray, n);
        cout << " | k=" << k << "\n";

        // Precondition: 1 <= k <= n holds, so we just call kSmall.
        int val = kSmall(a, 0, n - 1, k);
        cout << k << "(th) result: " << val << "\n";
        cout << "array after kSmall: ";
        print(a, n);
        cout << "\n\n";

        delete[] a;
    }

    //Case 2: kth is the pivot (example: k=4 -> 4)
    {
        int* a = new int[n];
        copyarr(defaultarray, a, n);
        int k = 4;
        cout << "[Pivot case] base: ";
        print(defaultarray, n);
        cout << " | k=" << k << "\n";

        int val = kSmall(a, 0, n - 1, k);
        cout << k << "(th) smallest: " << val << "\n";
        cout << "array after kSmall function: ";
        print(a, n);
        cout << "\n\n";

        delete[] a;
    }

    //Case 3: kth is in S2 (right partition)
    {
        int* a = new int[n];
        copyarr(defaultarray, a, n);
        int k = 5; // 5th smallest = 8 -> in S2 relative to pivot=6
        cout << "[S2 case] base: ";
        print(defaultarray, n);
        cout << " | k=" << k << "\n";

        int val = kSmall(a, 0, n - 1, k);
        cout << k << "(th) smallest: " << val << "\n";
        cout << "array after kSmall function: ";
        print(a, n);
        cout << "\n\n";

        delete[] a;
    }

    return 0;
}
