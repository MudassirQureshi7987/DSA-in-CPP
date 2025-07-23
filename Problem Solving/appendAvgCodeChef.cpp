#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        sort(a.begin(), a.end());
        int x = a[0], y = a[1];

        int avg = (x + y + 1) / 2;

        while (k > 0 && x + 1 < y) {
            avg = (x + y + 1) / 2;
            sum += avg;
            y = avg;
            --k;
        }

        sum += 1LL * k * avg;

        cout << sum << '\n';
    }

    return 0;
}
