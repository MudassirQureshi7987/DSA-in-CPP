#include<iostream>
using namespace std;

bool isKthBitSet(int n, int k) {
    // Check if the k-th bit is set in the binary representation of n
    return (n & (~(1 << (k - 1))));
}