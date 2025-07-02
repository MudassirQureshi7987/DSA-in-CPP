class Solution {
  public:
    int toggleBits(int n, int l, int r) {
        // Toggle bits from l to r in the binary representation of n
        // l and r are 1-based indices
        // We will use XOR operation to toggle bits
        // basic formula to toggle bits is n ^ (1 << i-1)
        // where i is the bit position (1-based index)
        for(int i = l;i <= r;i++)
        {
            n = (n ^ (1 << i-1));
        }
        return n;
     
    }
};