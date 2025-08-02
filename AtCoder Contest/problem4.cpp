#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    // Each present: P = value, A = mood increase, B = mood decrease
    vector<tuple<int, int, int>> presents(N);

    for (int i = 0; i < N; ++i) {
        int P, A, B;
        cin >> P >> A >> B;
        presents[i] = {P, A, B};
    }

    int Q;
    cin >> Q;

    vector<long long> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i];
    }

    for (int i = 0; i < Q; ++i) {
        long long mood = queries[i];

        for (int j = 0; j < N; ++j) {
            int P, A, B;
            tie(P, A, B) = presents[j];

            if (P >= mood) {
                mood += A;
            } else {
                mood = max(0LL, mood - B);
            }
        }

        cout << mood << '\n';
    }

    return 0;
}
