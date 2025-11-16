//
// Created by loxxy on 15.11.2025.
//

#include "ArrayGenerator.h"

#define MIN_VAl 0
#define MAX_VAl 6000
#define MIN_SIZE 500
#define MAX_SIZE 100000
#define STEP 100
#define MIN_COUNT 5

constexpr int MAX_COUNT = (MAX_SIZE - MIN_SIZE) / STEP + 1;

void ArrayGenerator::generateBaseArrays(int n) {
    _randomVector.resize(n);
    _backwardVector.resize(n);
    _almostSortedVector.resize(n);

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<> dis(MIN_VAl, MAX_VAl);

    // Random
    for (int i = 0; i < n; i++) {
        _randomVector[i] = dis(mt);
    }

    // Backwards sorted
    for (int i = 0; i < n; i++) {
        _backwardVector[i] = n - i;
    }

    // Almost sorted
    for (int i = 0; i < n; i++) {
        _almostSortedVector[i] = i + 1;
    }

    std::mt19937 rng(987654);
    std::uniform_int_distribution<int> dist(0, n - 1);

    // Swapping n/100 random elements
    for (int i = 0; i < n / 100; i++) {
        int a = dist(rng);
        int b = dist(rng);
        std::swap(_almostSortedVector[a], _almostSortedVector[b]);
    }
}

vector<int> ArrayGenerator::generateRandomArray(int n) const {
    return vector<int>(_randomVector.begin(), _randomVector.begin() + n);
}

vector<int> ArrayGenerator::generateBackwardsArray(int n) const {
    return vector<int>(_backwardVector.begin(), _backwardVector.begin() + n);
}

vector<int> ArrayGenerator::generateAlmostSortedArray(int n) const {
    return vector<int>(_almostSortedVector.begin(), _almostSortedVector.begin() + n);
}