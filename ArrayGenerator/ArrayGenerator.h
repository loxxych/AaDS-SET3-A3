//
// Created by loxxy on 15.11.2025.
//

#ifndef SET3_ARRAYGENERATOR_H
#define SET3_ARRAYGENERATOR_H

#include <vector>
#include <random>

using namespace std;

class ArrayGenerator {
private:
    vector<int> _randomVector;
    vector<int> _backwardVector;
    vector<int> _almostSortedVector;

public:
    void generateBaseArrays(int maxSize);

    vector<int> generateRandomArray(int n) const;
    vector<int> generateBackwardsArray(int n) const;
    vector<int> generateAlmostSortedArray(int n) const;
};

#endif //SET3_ARRAYGENERATOR_H