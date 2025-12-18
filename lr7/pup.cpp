#include "pch.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <ctime>

double distance(const std::vector<double>& a, const std::vector<double>& b) {
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        double d = a[i] - b[i];
        sum += d * d;
    }
    return sqrt(sum);
}

double timeT(long long iterations, const std::vector<double>& a, const std::vector<double>& b) {
    clock_t start_time = clock();

    double total = 0.0;
    for (long long i = 0; i < iterations; ++i) {
        double result = distance(a, b);
        total += result;
    }

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;

    
    if (total > 1e100) std::cout << "error";

    return time_taken;
}

int main() {
    std::vector<double> a{ 1.0, 2.0, 3.0 };
    std::vector<double> b{ 4.0, 5.0, 6.0 };

    
    long long test_cases[] = { 1'000'000, 10'000'000 };

    for (auto iterations : test_cases) {
        double time_taken = timeT(iterations, a, b);
        std::cout << "\nIterations: " << iterations << '\n';
        std::cout << "All time: " << time_taken << " second\n";
        std::cout << "-----------------------------\n";
    }

    return 0;
}
