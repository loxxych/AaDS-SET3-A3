//
// Created by loxxy on 15.11.2025.
//

#include <chrono>
#include "SortTester.h"

#define MAX_SIZE 100000
#define ITERATIONS 5

SortTester::SortTester() {
    _sorter = new Sorter();
    _generator = new ArrayGenerator();

    _generator->generateBaseArrays(MAX_SIZE);
}

// Time measuring functions
long long SortTester::measureQuickTime(vector<int> &arr) {
    auto start = std::chrono::high_resolution_clock::now();

    _sorter->quickSort(arr, 0, arr.size() - 1);

    const auto elapsed = std::chrono::high_resolution_clock::now() - start;
    const long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();

    return msec;
}

long long SortTester::measureIntroTime(vector<int>& arr) {
    const auto start = std::chrono::high_resolution_clock::now();

    const auto n = arr.size();
    _sorter->introsort(arr, 0, n - 1, 2 * log2(n));

    const auto elapsed = std::chrono::high_resolution_clock::now() - start;
    const long long msec = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();

    return msec;
}

// Utility functions
long long SortTester::averageQuickSortingTime(vector<int>& arr) {
    long long total = 0;

    for (size_t i = 0; i < ITERATIONS; i++) {
        total += measureQuickTime(arr);
    }

    // Average time
    return total / ITERATIONS;
}

long long SortTester::averageIntroSortingTime(vector<int>& arr) {
    long long total = 0;

    for (size_t i = 0; i < ITERATIONS; i++) {
        total += measureIntroTime(arr);
    }

    // Average time
    return total / ITERATIONS;
}

// Merge tests
long long SortTester::runQuickRegularTests(int n) {
    auto array = _generator->generateRandomArray(n);
    return averageQuickSortingTime(array);
}

long long SortTester::runQuickSortedBackwardsTests(int n) {
    auto array = _generator->generateBackwardsArray(n);
    return averageQuickSortingTime(array);
}

long long SortTester::runQuickAlmostSortedTests(int n) {
    auto array = _generator->generateAlmostSortedArray(n);
    return averageQuickSortingTime(array);
}

// Hybrid merge tests
long long SortTester::runIntroRegularTests(int n) {
    auto array = _generator->generateRandomArray(n);
    return averageIntroSortingTime(array);
}

long long SortTester::runIntroSortedBackwardsTests(int n) {
    auto array = _generator->generateBackwardsArray(n);
    return averageIntroSortingTime(array);
}

long long SortTester::runIntroAlmostSortedTests(int n) {
    auto array = _generator->generateAlmostSortedArray(n);
    return averageIntroSortingTime(array);
}