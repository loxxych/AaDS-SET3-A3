//
// Created by loxxy on 15.11.2025.
//

#ifndef SET3_SORTTESTER_H
#define SET3_SORTTESTER_H

#include <vector>
#include "../Sorter/Sorter.h"
#include "../ArrayGenerator/ArrayGenerator.h"

using namespace std;

class SortTester {
private:
    Sorter* _sorter;
    ArrayGenerator* _generator;
    vector<int> _randomArray;
    vector<int> _generatorReverse;
    vector<int> _generatorAlmost;

public:
    SortTester();

    long long measureQuickTime(vector<int> &arr);
    long long measureIntroTime(vector<int>& arr);

    long long averageQuickSortingTime(vector<int>& array);
    long long averageIntroSortingTime(vector<int>& array);

    long long runQuickRegularTests(int n);
    long long runQuickSortedBackwardsTests(int n);
    long long runQuickAlmostSortedTests(int n);

    long long runIntroRegularTests(int n);
    long long runIntroSortedBackwardsTests(int n);
    long long runIntroAlmostSortedTests(int n);
};


#endif //SET3_SORTTESTER_H