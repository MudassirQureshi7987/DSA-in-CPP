//C++ program to swap two numbers using XOR
#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10;

    // Print original values
    cout << "Before swapping: a = " << a << ", b = " << b << endl;

    // Swap using XOR
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    // Print swapped values
    cout << "After swapping: a = " << a << ", b = " << b << endl;

    return 0;
}

// why does this work?
// The XOR operation has the property that a ^ a = 0 and a ^ 0 = a.
// When you perform a = a ^ b, you store the XOR of a and b in a.
// Then, when you do b = a ^ b, you effectively retrieve the original value of a and store it in b.
// Finally, when you do a = a ^ b again, you retrieve the original value of b and store it in a.    
// This way, the values of a and b are swapped without using a temporary variable.
// This method is efficient and works for any integer values of a and b.
// Note: This method works for integers but may not be suitable for floating-point numbers or other data types.
// It is also important to note that this method can lead to issues if the same variable is used for both a and b, as it will result in a = 0.
// Therefore, it is generally recommended to use a temporary variable for clarity and safety in real-world applications.
// However, the XOR swap is a clever trick that demonstrates the power of bit manipulation in programming.
//   a = a ^ b; // Step 1: a now holds the XOR of a and b
//   b = a ^ b; // Step 2: b now holds the original value of a // (because a = a ^ b, so b = (a ^ b) ^ b = a)
//   a = a ^ b; // Step 3: a now holds the original value of b // (because a = a ^ b, so a = (a ^ b) ^ a = b)
//
// This method is efficient and works for any integer values of a and b.
