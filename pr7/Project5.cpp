#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>


void printArray(const int* arrA, int size) {
       for (int i = 0; i < size; i++) {
           std::cout << arrA[i] << " ";
       }

       std::cout << std::endl;
   }


void f26_1() {

    const int N = 10; 

    int A[N] = { 0 };
    int B[N] = { 0 };

    std::cout << "Enter " << N << " numbers for A: " << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int iB = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] % 2 != 0) {
            B[iB++] = A[i];
        }
    }

    printArray(B, N);

}


//////////////

void intersect(std::set<int> A, std::set<int> B) {
    for (int value : A) { 

        int tsize = B.size();

        if (value > 0) {
            B.insert(value);
            if (B.size() == tsize) {
                std::cout << value << " ";
            }
        }

    }

}
void f26_2() {

    int N; 

    std::set<int> A;
    std::set<int> B;

    std::cout << "Enter N: ";
    std::cin >> N;

    std::cout << "Enter " << N << " numbers for A: " << std::endl;
    for (int i = 0; i < N; i++) {
        int t;
        std::cin >> t;
        A.insert(t);
    }

    std::cout << "Enter " << N << " numbers for B: " << std::endl;
    for (int i = 0; i < N; i++) {
        int t;
        std::cin >> t;
        B.insert(t);
    }

    std::set<int> result;

    std::set_intersection(A.begin(), A.end(), B.begin(),
        B.end(),
        inserter(result, result.begin()));
    
    //intersect(A, B);

    // Print the result
    std::cout << "Intersection of two sets: ";
    for (int i : result)
        std::cout << i << " ";
}



int main() {
    //f26_1();

    f26_2();
    
    return 0;
}