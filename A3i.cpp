#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

random_device rd;
mt19937 mt(rd());

// Insertion sort
void insertionSort(vector<int>& arr, int l, int r) {
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
void heapify(vector<int> &v, const int l, const int r, const int i) {
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

void buildMaxHeap(vector<int> &v, const int l, const int r) {
    const size_t n = v.size();

    for (int i = (n / 2) - 1; i >= 0; --i) {
        heapify(v, l, r, i);
    }
}

// Heap sort
void heapSort(vector<int> &v, const int l, const int r) {
    const int n = r - l + 1;

    buildMaxHeap(v, l, r);

    for (int i = r; i > l; --i) {
        swap(v[l], v[i]);
        heapify(v, l, i - 1, 0);
    }

}

// Quick sort
int partition(vector<int>& arr, int l, int r) {
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

// Hybrid quick sort+heap sort
void introsort(vector<int> &v, const int l, const int r, const int recDepth) {
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

void printArray(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto& x : arr) {
        cin >> x;
    }

    introsort(arr, 0, n - 1, 2 * log2(n));
    printArray(arr);
}