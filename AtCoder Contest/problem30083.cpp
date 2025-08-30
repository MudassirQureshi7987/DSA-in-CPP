#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    vector<int> Apos;
    for (int i = 0; i < 2*N; i++) {
        if (S[i] == 'A') Apos.push_back(i);
    }

    // Target 1: A’s at even positions [0,2,4,...]
    long long cost1 = 0;
    for (int i = 0; i < N; i++) {
        cost1 += abs(Apos[i] - 2*i);
    }

    // Target 2: A’s at odd positions [1,3,5,...]
    long long cost2 = 0;
    for (int i = 0; i < N; i++) {
        cost2 += abs(Apos[i] - (2*i+1));
    }

    cout << min(cost1, cost2) << "\n";
    return 0;
}
