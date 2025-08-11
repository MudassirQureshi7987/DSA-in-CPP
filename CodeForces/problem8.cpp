#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int ans = 0;
        while(true)
        {
            bool step1 = false, step2 = false;
            for(int i = 0; i < n; i++)
            {
                if(a[i] > b[i])
                {
                    a[i]--;
                    step1 = true;
                }
                else if(a[i] < b[i])
                {
                    a[i]++;
                    step2 = true;
                }
            }
            if(!step1 && !step2) break;
            ans++;
        }
        
        cout << ans << endl;
    }
}