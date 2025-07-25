#include <bits/stdc++.h>

using namespace std;



#pragma GCC optimize("unroll-loops")

#pragma GCC optimize("O3,unroll-loops")

#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")



typedef long long ll;

const int MOD = 1e9+7;



#define SUVRAT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);



int main()

{

    SUVRAT



    ll t;

    cin >> t;

    while(t--)

    {

        ll n;

        cin >> n;

        vector <ll> v(n, 0);

        for(ll i = 0 ; i < n ; i++) cin >> v[i];



        sort(v.begin(), v.end());

        reverse(v.begin(), v.end()); 



        for(ll i = 1 ; i < n ; i++) v[i] += v[i-1];





        for(ll k = 1 ; k <= 2*n ; k++)

        {

            ll ans = 0;

            ll p = (k+1)/2;

            for(ll take = p ; take <= n ; take++)

            {

                ll cur = 0;

                if(take > k) continue;

                cur += v[take-1];

                ll left = k - take;

                cur += left*take - (left*(left+1))/2;

                ans = max(ans, cur);

            }

            cout << ans << " ";

        }

        cout << endl;

    }



    return 0;

}