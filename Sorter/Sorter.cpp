//
// Created by loxxy on 15.11.2025.
//

#include "Sorter.h"

#include <random>

#define THRESHOLD 15

random_device rd;
mt19937 mt(rd());

void Sorter::insertionSort(vector<int>& arr, int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= l && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

// Heap sort
void Sorter::heapify(vector<int> &v, const int l, const int r, const int i) {
    int max_ind = i;
    const int size = r - l + 1;

    const int left  = 2 * i + 1;
    const int right = 2 * i + 2;

    if (left < size && v[l + left] > v[l + max_ind])
        max_ind = left;
    if (right < size && v[l + right] > v[l + max_ind])
        max_ind = right;

    if (max_ind != i) {
        swap(v[l + i], v[l + max_ind]);
        heapify(v, l, r, max_ind);
    }
}

void Sorter::buildMaxHeap(vector<int> &v, const int l, const int r) {
    const size_t n = v.size();

    for (int i = (n / 2) - 1; i >= 0; --i) {
        heapify(v, l, r, i);
    }
}

// Heap sort
void Sorter::heapSort(vector<int> &v, const int l, const int r) {
    const int n = r - l + 1;

    buildMaxHeap(v, l, r);

    for (int i = r; i > l; --i) {
        swap(v[l], v[i]);
        heapify(v, l, i - 1, 0);
    }

}

// Quick sort
int Sorter::partition(vector<int>& arr, int l, int r) {
    uniform_int_distribution<> dis(l, r);
    int pivotIndex = dis(mt);

    const int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[r]);

    int i = l - 1;

    for (int j = l; j <= r - 1; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[r]);
    return i + 1;
}

// Quick sort
void Sorter::quickSort(vector<int>& arr, int l, int r) {
    const int n = r - l + 1;

    if (l < r) {
        const auto part = partition(arr, l, r);

        quickSort(arr, l, part - 1);
        quickSort(arr, part + 1, r);
    }
}

// Hybrid quick sort+heap sort
void Sorter::introsort(vector<int> &v, const int l, const int r, const int recDepth) {
    const int n = r - l + 1;

    if (n < 16) {
        insertionSort(v, l, r);
        return;
    }

    if (recDepth == 0) {
        heapSort(v, l, r);
        return;
    }

    if (l < r) {
        const auto part = partition(v, l, r);

        introsort(v, l, part - 1, recDepth - 1);
        introsort(v, part + 1, r, recDepth - 1);
    }
}