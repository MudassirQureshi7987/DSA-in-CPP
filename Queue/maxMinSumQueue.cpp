#include<iostream>
#include<queue>
using namespace std;

int solve(int *arr,int n,int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    // 1 window ban chuki hai bhai
    for(int i = 0;i < k;i++)
    {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    ans += arr[mini.front()] + arr[maxi.front()];

    for(int i = k;i < n;i++)
    {
        //purane window ke bahar ke elements nikal lege
        while(!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[mini.front()] + arr[maxi.front()];
    }

    return ans;
}

int main() {


    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;


    return 0;
}