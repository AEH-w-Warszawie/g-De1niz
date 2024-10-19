#include <iostream>
#include <chrono>
#include <cassert>
#include <cmath>

using namespace std;
using namespace chrono;

long long GCD(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void unit_tests() {
    assert(GCD(pow(10, 3), 3) == 1);
        assert(GCD(pow(10, 6), 3) == 1);
        assert(GCD(pow(10, 10), 3) == 1);
    cout << "All tests passed!" << endl;
}

void measure_execution_time(long long a, long long b) {
    auto start = high_resolution_clock::now();
    long long result = GCD(a, b);
    auto stop = high_resolution_clock::now();
    cout << "GCD (" << a << ", " << b << "): " << result
         << ", Time: " << duration_cast<nanoseconds>(stop - start).count() << " ns" << endl;
}

int main () {
    unit_tests();
    cout << endl << "Measuring execution times:" << endl;

   
    for (long long i = 3; i <= 10; i++) {
        long long a = pow(10, i);
        measure_execution_time(a, 3);
    }

    return 0;
}
