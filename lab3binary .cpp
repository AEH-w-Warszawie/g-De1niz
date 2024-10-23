#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

unsigned int findTrivial(const std::vector<unsigned int>& v, unsigned int key) {
    for (unsigned int i = 0; i < v.size(); ++i) {
        if (v[i] == key) return i;
    }
    return -1;
}

unsigned int findBinary(const std::vector<unsigned int>& v, unsigned int key) {
    int  low = 0, high = v.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v[mid] == key) return mid;
        else if (v[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    std::vector<unsigned int> v(1000000);
    for (unsigned int i = 0; i < 1000000; ++i) v[i] = i;

    unsigned int key;
    std::cout << "Enter a number: ";
    std::cin >> key;

    auto start1 = std::chrono::high_resolution_clock::now();
    findTrivial(v, key);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << "Trivial: " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds." << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    findBinary(v, key);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::cout << "Binary: " << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << " microseconds." << std::endl;

    return 0;
}

