// Cpp program to unset the rightmost
// set bit using Subtracting by One
#include <bits/stdc++.h>
using namespace std;

// unsets the rightmost set bit 
// of n and returns the result 
int unsetLSB(int n)  { 
    return (n & (n - 1));
} 

// When we subtract a number by 1, all bits after the rightmost set bit (including it) are toggled. For example : 
//10 in binary is 00001010 and 9 in binary is 00001001 
//8 in binary is 00001000 and 7 in binary is 00000111 
// So, when we do n & (n - 1), it unsets the rightmost set bit of n.
// This works because the rightmost set bit is the only bit that is different between n and n - 1, so all other bits remain unchanged.


// Using 2's Complement
 //            N = 1001110 (78)
//2's compliment = 0110010
//     N & (-N) = 0000010
//N - (N & (-N)) = 1001100 (76)

//Explanation:
// The 2's complement of a number is obtained by inverting all bits and adding 1 to the result.
int unsetLSBUsingTwosComplement(int n) {
    return n - (n & -n);
}

