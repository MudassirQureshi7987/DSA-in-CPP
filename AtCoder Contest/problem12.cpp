#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    long long minR = LLONG_MAX, maxR = LLONG_MIN;
    long long minC = LLONG_MAX, maxC = LLONG_MIN;

    for (int i = 0; i < N; ++i) {
        long long R, C;
        cin >> R >> C;
        minR = min(minR, R);
        maxR = max(maxR, R);
        minC = min(minC, C);
        maxC = max(maxC, C);
    }

    auto ceil_div2 = [](long long x) -> long long { return (x + 1) / 2; };
    long long tRow = ceil_div2(maxR - minR);
    long long tCol = ceil_div2(maxC - minC);
    long long answer = max(tRow, tCol);

    cout << answer << "\n";
    return 0;
}
