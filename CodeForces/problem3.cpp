#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    long long count = 0;
    unordered_map<int, int> freq;

    for(int j = 0; j < n; j++) {
        int key = j - A[j];
        if(freq.find(key) != freq.end()) {
            count += freq[key];
        }

        int sum = j + A[j]; // This becomes i + A[i] for future iterations
        freq[sum]++;
    }

    cout << count << endl;
    return 0;
}