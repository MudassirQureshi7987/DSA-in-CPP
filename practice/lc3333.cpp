#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1e9 + 7;


    long long solve(int i,int count,vector<int>& freq,int k,vector<vector<int>>& dp)
    {
        if(i >= freq.size())
        {
            if(count < k)
            {
                return 1;
            }
            return 0;
        }

        if(dp[i][count] != -1)
        {
            return dp[i][count];
        }

        long long result = 0;

        for(int take = 1;take <= freq[i];take++)
        {
            if(count + take < k)
            {
                result = (result + solve(i+1,count+take,freq,k,dp)) % M; 
            } else
            {
                break;
            }
        }
        return dp[i][count] = result;
    }
    int possibleStringCount(string word, int k) {
        int n = word.length();
        if(k > n)   return 0;

        vector<int> freq;
        int count = 1;
        for(int i = 1;i < n;i++)
        {
            if(word[i] == word[i-1])
            {
                count++;
            }
            else
            {
                freq.push_back(count);
                count = 1;
            }
        }
        freq.push_back(count);

        long long P = 1;  // total possible strings
        for(int &f : freq)
        {
            P = (P * f) % M;
        }

        if(freq.size() > k)
        {
            return P; // all of them are valid
        }

        vector<vector<int>> dp(n+1,vector<int>(k + 1,-1));  

        long long invalidCount = solve(0,0,freq,k,dp);

        return (P - invalidCount + M) % M;
    }
};