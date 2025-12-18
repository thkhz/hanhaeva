#include "pch.h"
#include "Header.h"
#include <cmath>
#include <iostream>
#include <ctime>

#ifdef _WIN32
#define DISTANCE_EXPORTS
#endif


double Distance(const double* a, const double* b, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double d = a[i] - b[i];
        sum = sum +  (d * d);
    }
    return sqrt(sum);
}

double timeD(const double* a, const double* b, int vector_size, int N) {
    clock_t start_time = clock(); 

    double total = 0.0;
    for (int i = 0; i < N; ++i) {
        double result = Distance(a, b, vector_size); 
        total += result; 
    }

    clock_t end_time = clock(); 
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC; 

    return time_taken;
}