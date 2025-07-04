#include <iostream>
#include <cmath>

int main() {
    double number = 15;
    double result = log2(number);  // returns 4, because 2^4 = 16

    std::cout << "log2(" << number << ") = " << result << std::endl;
    return 0;
}