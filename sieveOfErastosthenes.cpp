#include<iostream>
#include<vector>
using namespace std;

int sieveOfErastosthenes(int n)
{
    vector<bool> prime(n+1,true);
    int count = 0;

    prime[0] = prime[1] = false;

    for(int i = 0;i<n;i++)
    {
        if(prime[i])
        {
            count++;

            for(int j = i*i;j<n;j = j + i)
            {
                prime[j] = false;
            }
        }

       
    }
    return count;
}

int main()
{
    int n;
    cin>>n;

    int ans = sieveOfErastosthenes(n);
    cout<<ans<<endl;
}