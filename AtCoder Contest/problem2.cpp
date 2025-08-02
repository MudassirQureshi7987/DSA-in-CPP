#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> arr1(n);
    unordered_map<int,int> arr2;

    for(int i = 0;i < n;i++)
    {
        cin >> arr1[i];
    }

    for(int i = 0;i < m;i++)
    {
        int x;
        cin >> x;

        arr2[x]++;
    }

    for(int i = 0;i < n;i++)
    {
        if(arr2[arr1[i]] > 0)   
        {
            arr2[arr1[i]]--;
            continue ;
        }

        cout << arr1[i] << " ";

    }
}