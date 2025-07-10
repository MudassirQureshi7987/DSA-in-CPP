#include<bits/stdc++.h>
using namespace std;

// C++ Templates

// Templates let you write a function or class that works with different data types.

// They help avoid repeating code and make programs more flexible. 

// C++ Function Templates

// You can create a function template by using the template keyword:

// Syntax :

// template <typename T>
// return_type function_name(T parameter) {
//   // code
// } 
 
// T is a placeholder for a data type (like int, float, etc.).
// You can use any name instead of T, but T is common.

// Example

template <typename T>
T add(T a, T b) {
  return a + b;
}

int main() {
  cout << add<int>(5, 3) << "\n";
  cout << add<double>(2.5, 1.5) << "\n";
  return 0;
}

// In the example above, add<int>(5, 3) tells the compiler to use int for T, while add<double>(2.5, 1.5) tells it to use double.


