#include <iostream>
#include <chrono>
#include <cmath> // for power
#include <cassert> // For unit testing

using namespace std;
using namespace chrono;


long long GCD_subtraction(long long a, long long b) {
    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}


long long GCD_modulo(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void unit_tests() {
    
    assert(GCD_subtraction(103, 3) == 1);
    assert(GCD_modulo(103, 3) == 1);

    assert(GCD_subtraction(106, 3) == 1);
    assert(GCD_modulo(106, 3) == 1);

    assert(GCD_subtraction(1010, 3) == 1);
    assert(GCD_modulo(1010, 3) == 1);

    cout << "All tests passed!" << endl;
}


void measure_execution_time(long long (*gcd_func)(long long, long long), long long a, long long b, const string& method_name) {
    auto start = high_resolution_clock::now();
    long long result = gcd_func(a, b);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "GCD (" << a << ", " << b << ") by " << method_name << " method: " << result
         << ", Time: " << duration.count() << " ns" << endl;
}

int main() {
 
    unit_tests();

    cout << endl << "Measuring execution times:" << endl;

    // Large inputs using powers of 10
    long long a1 = pow(10, 3); // Or use 1e3
    long long b1 = 3;
    measure_execution_time(GCD_subtraction, a1, b1, "subtraction");
    measure_execution_time(GCD_modulo, a1, b1, "modulo");

    long long a2 = pow(10, 6); // Or use 1e6
    long long b2 = 3;
    measure_execution_time(GCD_subtraction, a2, b2, "subtraction");
    measure_execution_time(GCD_modulo, a2, b2, "modulo");

    long long a3 = pow(10, 10); // Or use 1e10
    long long b3 = 3;
    measure_execution_time(GCD_subtraction, a3, b3, "subtraction");
    measure_execution_time(GCD_modulo, a3, b3, "modulo");

    return 0;
}

