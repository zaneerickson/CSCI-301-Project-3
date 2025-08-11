
/*
 * CSCI 301 – Project 3: kSmall (Recursive kth Smallest)
 * Student: TODO: Your StarID and Name
 * Due Date: TODO
 * Instructor: TODO
 *
 * Description:
 *   Test harness for kSmall using dynamic arrays and pointer parameters.
 *   Demonstrates the three required scenarios:
 *     1) kth smallest in S1 (left partition)
 *     2) kth smallest is the pivot
 *     3) kth smallest in S2 (right partition)
 *
 * How to compile:
 *   g++ -std=c++17 -O2 -Wall demo_main.cpp -o demo
 *
 * How to run:
 *   ./demo
 *
 * Notes:
 *   - Arrays are allocated with new[] to satisfy the assignment's dynamic
 *     allocation requirement.
 *   - This file is just a demo. If your course provided a separate test.cpp,
 *     prefer compiling that with kSmall.h instead.
 */

#include <iostream>
#include <vector>
#include "kSmall.h"
using namespace std;

static void print_vec(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i + 1 == v.size() ? "" : " ");
    }
}

static void print_arr(const int* a, int n) {
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i + 1 == n ? "" : " ");
    }
}

int main() {
    // ---------- Case 1: kth is in S1 (left partition)
    // Use the same base array but choose k so that k < pivot's rank.
    {
        vector<int> base = {6, 3, 1, 10, 8, 4};
        const int n = (int)base.size();
        int* a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = base[i];

        int k = 2; // 2nd smallest = 3 -> should be in S1 relative to pivot=6
        cout << "[S1 case] base: ";
        print_vec(base);
        cout << " | k=" << k << "\n";

        try {
            int val = kSmall(a, 0, n - 1, k);
            cout << "kSmall result: " << val << "\n";
            cout << "array after kSmall: ";
            print_arr(a, n);
            cout << "\n\n";
        } catch (const exception& e) {
            cout << "error: " << e.what() << "\n\n";
        }
        delete[] a;
    }

    // ---------- Case 2: kth is the pivot (matches assignment's example)
    {
        vector<int> base = {6, 3, 1, 10, 8, 4};
        const int n = (int)base.size();
        int* a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = base[i];

        int k = 4; // from assignment: pivot=6 ends up as 4th smallest
        cout << "[Pivot case] base: ";
        print_vec(base);
        cout << " | k=" << k << "\n";

        try {
            int val = kSmall(a, 0, n - 1, k);
            cout << "kSmall result: " << val << "\n";
            cout << "array after kSmall: ";
            print_arr(a, n);
            cout << "\\n\\n";
        } catch (const exception& e) {
            cout << "error: " << e.what() << "\n\n";
        }
        delete[] a;
    }

    // ---------- Case 3: kth is in S2 (right partition)
    {
        vector<int> base = {6, 3, 1, 10, 8, 4};
        const int n = (int)base.size();
        int* a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = base[i];

        int k = 5; // 5th smallest = 8 -> in S2 relative to pivot=6
        cout << "[S2 case] base: ";
        print_vec(base);
        cout << " | k=" << k << "\n";

        try {
            int val = kSmall(a, 0, n - 1, k);
            cout << "kSmall result: " << val << "\n";
            cout << "array after kSmall: ";
            print_arr(a, n);
            cout << "\n\n";
        } catch (const exception& e) {
            cout << "error: " << e.what() << "\n\n";
        }
        delete[] a;
    }

    // ---------- Extra: demonstrates the S1-empty edge case (no swaps needed)
    {
        vector<int> base = {1, 3, 5, 2, 19, 3, 4}; // pivot=1, S1 is empty
        const int n = (int)base.size();
        int* a = new int[n];
        for (int i = 0; i < n; ++i) a[i] = base[i];

        int k = 1; // smallest is the pivot itself
        cout << "[S1 empty edge case] base: ";
        print_vec(base);
        cout << " | k=" << k << "\n";

        try {
            int val = kSmall(a, 0, n - 1, k);
            cout << "kSmall result: " << val << "\n";
            cout << "array after kSmall: ";
            print_arr(a, n);
            cout << "\\n";
        } catch (const exception& e) {
            cout << "error: " << e.what() << "\n";
        }
        delete[] a;
    }

    return 0;
}
