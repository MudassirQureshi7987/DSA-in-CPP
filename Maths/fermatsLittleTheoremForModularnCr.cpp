#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
vector<long long> fact(MAX);

// 🔁 Precompute all factorials mod MOD
void computeFactorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

// ⚙️ Binary Exponentiation — from your `solve` method
long long modPow(long long x, long long n) {
    long long ans = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            ans = (ans * x) % MOD;
            n--;
        } else {
            x = (x * x) % MOD;
            n /= 2;
        }
    }
    return ans;
}

// 🧮 Modular nCr using Fermat's Little Theorem
int modularnCr(int n, int r) {
    if (r < 0 || r > n) return 0;

    long long numerator = fact[n];
    long long denominator = (fact[r] * fact[n - r]) % MOD;
    long long inverse = modPow(denominator, MOD - 2); // Fermat's inverse

    return (numerator * inverse) % MOD;
}