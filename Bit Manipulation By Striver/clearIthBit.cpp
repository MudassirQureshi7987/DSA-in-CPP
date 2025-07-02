#include<iostream>
using namespace std;

bool clearIthBit(int n, int k) {
    // Clear the k-th bit in the binary representation of n
    return (n & (~(1 << (k - 1))));
}