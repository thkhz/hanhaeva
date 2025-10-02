
#include <iostream>
#include <cmath>


int main() 
{
	float x, y;
	std::cin >> x;
	std::cin >> y;


	float R = sqrt(x * x + y * y) / exp(log(x));
	float S = pow(cos(3.1415926 / 4 * x), 2);

	std::cout << R << std::endl;
	std::cout << S << std::endl;

	float C = std::max(R, S);
	std::cout << C << std::endl;

	system("pause");

	return 0;

}