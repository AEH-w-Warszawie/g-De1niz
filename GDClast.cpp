
#include <iostream> // input , output
#include <chrono> // for time measure
using namespace std;

unsigned long long GCD_substraction(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}


unsigned long long GCD_modulo(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        b = a % b;
        a = b;
    }
    return a;
}

int main() {
    unsigned long long numbers[][2] = {
        {1000, 3},           // 10^3
        {1000000, 3},        // 10^6
        {10000000000ULL, 3}  // 10^10
    };

    for (auto& pair : numbers) {
        unsigned long long a = pair[0];
        unsigned long long b = pair[1];

        // Time measurement: Subtraction
        auto start = chrono::high_resolution_clock::now();
        GCD_substraction(a, b);
        auto end = chrono::high_resolution_clock::now();
        auto duration_substraction = chrono::duration_cast<  chrono::microseconds>(end - start).count();

        // Time measurement
        start = chrono::high_resolution_clock::now();
        GCD_modulo(a, b);
        end = chrono::high_resolution_clock::now();
        auto duration_modulo = chrono::duration_cast< chrono::microseconds>(end - start).count();

        cout << "GCD(" << a << ", " << b << ") - output time: " << duration_substraction << endl;
        cout << "GCD(" << a << ", " << b << ") - Mod time: " << duration_modulo << endl;
        
    }

    return 0;
}

