#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cmath> // For sqrt() function

using namespace std;

// Improved divisors function
vector<unsigned long long> divisors(unsigned long long number) {
    vector<unsigned long long> result;
    unsigned long long sqrt_num = sqrt(number);
    for (unsigned long long i = 1; i <= sqrt_num; ++i) {
        if (number % i == 0) {
            result.push_back(i);
            if (i != number / i) {
                result.push_back(number / i);
            }
        }
    }
    return result;
}

int main() {
    unsigned long long number;
    cout << "Enter a number: ";
    cin >> number;

    // Start time measurement
    auto start = chrono::high_resolution_clock::now();
    
    // Find the divisors
    vector<unsigned long long> divs = divisors(number);

    // End time measurement
    auto end = chrono::high_resolution_clock::now();
    
    // Calculate elapsed time
    chrono::duration<double> duration = end - start;

    // Print dividers
    cout << "Divisors of " << number << " are: ";
    for (unsigned long long div : divs) {
        cout << div << " ";
    }
    cout << endl;

    // Print elapsed time
    cout << fixed << setprecision(6);
    cout << "Time taken: " << duration.count() << " seconds" << endl;

    return 0;
}

