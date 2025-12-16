#include <iostream>
#include "prim.h"

int main()
{
    float x, y;
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;

    float result = prim(x, y);
    std::cout << "Result = " << result << std::endl;

    system("pause");
    return 0;
}

