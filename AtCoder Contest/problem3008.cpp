#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    int X;
    string Y;
    cin >> X >> Y;

    cout << (S[X-1] == Y ? "Yes" : "No") << '\n';
    return 0;
}



