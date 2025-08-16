#include<bits/stdc++.h>
using namespace std;

int main(){

    int q;
    cin >> q;

    priority_queue<int,vector<int>,greater<int>> pq;
    while(q--)
    {
        int type;
        cin >> type;

        if(type == 2)
        {
            cout << pq.top() << endl;
            pq.pop();
        }
        else if(type == 1)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
    }
}