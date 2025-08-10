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
        for(int i = 0;i < n;i++)
        {
            cin >> a[i];
        }

        for(int i = 0;i < n;i++)
        {
            cin >> b[i];
        }

        bool step1 = true;
        bool step2 = true;
        int ans = 0;
        while(step1 != false)
        {
            step1 = false;
            step2 = false;
            for(int i = 0;i < n;i++)
            {
                if(step1 == false && a[i] > b[i])
                {
                    a[i]--;
                    step1 = true;
                }

                if(step2 == false && a[i] < b[i])
                {
                    a[i]++;
                    step2 = true;
                }

                if(step1 && step2)
                {
                    break;
                }
            }
            ans++;
        }
        
        cout << ans << endl;
    }
}