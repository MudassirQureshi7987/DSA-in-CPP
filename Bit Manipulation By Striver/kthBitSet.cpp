#include<iostream>
using namespace std;

bool isKthBitSet(int n, int k)
{
    int i = 1 << (k - 1); //using left shift to create a bitmask for the k-th bit
    // Note: k is 1-based index, so we subtract 1 to convert it to 0-based index for bit manipulation
    return ((n & i) != 0);
}

// Explanation:
// 1. `1 << (k - 1)` creates a bitmask with the k-th bit set.
// 2. `n & i` performs a bitwise AND operation between `n` and the bitmask.
// 3. If the result is not zero, it means the k-th bit in `n` is set (1), otherwise it is not set (0).

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        // Your code here
        // using right shift
        return ((n >> k) & 1 != 0);  // is it using right shift and 0 base indexing other than left shift and 1 base indexing?
    }
};// Example usage