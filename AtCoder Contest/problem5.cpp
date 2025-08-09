#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;

    if (n >= 3 && s[n-1] == 'a' && s[n-2] == 'e' && s[n-3] == 't') {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

