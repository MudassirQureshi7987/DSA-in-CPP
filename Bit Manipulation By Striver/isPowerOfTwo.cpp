class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)    return false;
        return (n & (n-1)) == 0;
    }
};

// Explanation:
// A number is a power of two if it has exactly one bit set in its binary representation.
// This can be checked using the expression (n & (n - 1)) == 0, which will be true for powers of two.
// The condition n > 0 ensures that we do not consider negative numbers or zero, which are not powers of two.
// the expression (n & (n - 1)) works because subtracting 1 from a power of two flips all bits after the rightmost set bit, resulting in a bitwise AND with the original number yielding zero.
// For example:
// - For n = 4 (100 in binary), n - 1 = 3 (011 in binary), so (4 & 3) = 0.
// - For n = 8 (1000 in binary), n - 1 = 7 (0111 in binary), so (8 & 7) = 0.
// - For n = 16 (10000 in binary), n - 1 = 15 (01111 in binary), so (16 & 15) = 0.
// - For n = 0 or negative numbers, the condition will return false since they are not powers of two.