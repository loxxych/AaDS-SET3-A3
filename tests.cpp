#include <fstream>
#include <iostream>

#include "SortTester/SortTester.h"

#define MIN_SIZE 500
#define MAX_SIZE 100000
#define STEP 100

using namespace std;

int main() {
    SortTester tester;

    ofstream out("tests.csv");

    // Writing header
    out << "size,"
        << "quick_random,intro_random,"
        << "quick_reverse,intro_reverse,"
        << "quick_almost,intro_almost\n";

    for (int size = MIN_SIZE; size <= MAX_SIZE; size += STEP) {

        // Initializing tests
        const long long qr = tester.runQuickRegularTests(size);
        const long long ir = tester.runIntroRegularTests(size);

        const long long qrev = tester.runQuickSortedBackwardsTests(size);
        const long long irev = tester.runIntroSortedBackwardsTests(size);

        const long long qal = tester.runQuickAlmostSortedTests(size);
        const long long ial = tester.runIntroAlmostSortedTests(size);

        // Writing row
        out << size << ","
            << qr << "," << ir << ","
            << qrev << "," << irev << ","
            << qal << "," << ial << "\n";

        cout << "Exported i = " << size << "\n";
    }
    out.close();
}
