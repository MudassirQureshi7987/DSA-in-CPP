#include<iostream>
using namespace std;

int clearIthBit(int n, int k) {
    // Clear the k-th bit in the binary representation of n
    // k is 1-based index, so we subtract 1 to convert it to 0-based index for bit manipulation
    return (n & (~(1 << (k - 1))));
}