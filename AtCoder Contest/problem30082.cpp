#include<bits/stdc++.h>
using namespace std;

long long fun(long long num)
{
    string alpha = to_string(num);
    reverse(alpha.begin(), alpha.end());
    int i = 0, n = alpha.size();

    while (i < n && alpha[i] == '0') i++;

    alpha = alpha.substr(i);
    if (alpha.empty()) return 0;

    return stoll(alpha); // use long long
}


int main() {
    long long x, y;
    cin >> x >> y;

    for (int i = 3; i <= 10; i++) {
        long long a = fun(x + y);
        x = y;
        y = a;
    }

    cout << y << endl;
}
