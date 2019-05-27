#include "functions.h"

void runPushback(std::vector<int> A, size_t n, int& loc) {
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < n; i++) {
        A.push_back(1);
        if (A.size() == A.capacity()) { loc++; }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "std::vector: " << std::fixed << std::setprecision(4) << diff.count() << " s, capacity: " << A.capacity() << endl;
}
void runPushback(Vector<int> A, size_t n, int& loc) {
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < n; i++) {
        A.push_back(1);
        if (A.size() == A.capacity()) { loc++; }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Vector: " << std::fixed << std::setprecision(4) << diff.count() << " s, capacity: " << A.capacity() << endl;
}
