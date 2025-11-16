//
// Created by loxxy on 15.11.2025.
//

#ifndef SET3_SORTER_H
#define SET3_SORTER_H

#include <vector>

using namespace std;

class Sorter {
public:
    void insertionSort(vector<int>& arr, int left, int right);
    void heapify(vector<int> &v, const int l, const int r, const int i);
    void buildMaxHeap(vector<int> &v, const int l, const int r);
    void heapSort(vector<int> &v, const int l, const int r);
    int partition(vector<int>& arr, int l, int r);
    void quickSort(vector<int>& arr, int l, int r);
    void introsort(vector<int> &v, const int l, const int r, const int recDepth);
};


#endif //SET3_SORTER_H