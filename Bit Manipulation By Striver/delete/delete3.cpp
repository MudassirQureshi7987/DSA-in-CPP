#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Deleting the 3rd bit
    n = n & ~(1 << 2);

    cout << "Number after deleting 3rd bit: " << n << endl;
    return 0;
}