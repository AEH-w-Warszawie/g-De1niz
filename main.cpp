#include <iostream>
#include <vector>
#include <chrono>

std::vector<unsigned long long> divisors(unsigned long long number) {
    std::vector<unsigned long long> result;
    for (unsigned long long i = 1; i <= number; ++i) {
        if (number % i == 0) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    unsigned long long number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    auto start = std::chrono::high_resolution_clock::now();
    
    std::vector<unsigned long long> divs = divisors(number);

    auto end = std::chrono::high_resolution_clock::now();
    
   
    std::chrono::duration<double> duration = end - start;

    std::cout << "Divisors of " << number << " are: ";
    for (unsigned long long div : divs) {
        std::cout << div << " ";
    }
    std::cout << std::endl;

    
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
}