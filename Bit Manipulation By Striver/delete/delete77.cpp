#include<iostream>
using namespace std;

int main() {
    int n = 5; // 0101 in binary
    int k = 2; // Clear the 2nd bit (1-based index)
    
    int result;
    cout << "Result after clearing the " << k << "th bit: " << result << endl; // Should print 1 (0001 in binary)
    
    return 0;
}