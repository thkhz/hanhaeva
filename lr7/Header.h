#pragma once

#ifdef DISTANCE_EXPORTS
#define DISTANCE_API __declspec(dllexport)
#else
#define DISTANCE_API __declspec(dllimport)
#endif

extern "C" {
    DISTANCE_API double Distance(const double* a, const double* b, int n);
    DISTANCE_API double timeD(const double* a, const double* b, int vector_size, int N);
}
