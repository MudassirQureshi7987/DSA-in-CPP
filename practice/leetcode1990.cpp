#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int left = firstPlayer;
        int right = secondPlayer;

        // base case
        if(left + right == n + 1)
        {
            return {1,1};
        }

        // mirroring left and right for edge case (cause they are symmetric so possible)
        if(left > n - right + 1)
        {
            int temp = n - left + 1;
            left = n - right + 1;
            right = temp; 
        }

        int minRound = n;
        int maxRound = 1;
        int nextRoundN = (n+1)/2;
        if(right <= nextRoundN) // case 1 : both on the same side
        {
            int countLeft = left - 1;
            int midCount = right - left - 1;

            for(int survivorsLeft = 0;survivorsLeft <= countLeft;survivorsLeft++)
            {
                for(int survivorsMid = 0;survivorsMid <= midCount;survivorsMid++)
                {
                    int pos1 = survivorsLeft + 1;
                    int pos2 = pos1 + survivorsMid + 1;
                    vector<int> tempResult = earliestAndLatest(nextRoundN,pos1,pos2);

                    minRound = min(minRound,1 + tempResult[0]);
                    maxRound = max(maxRound,1 + tempResult[1]);
                }
            }
        }
        else   // case 2 : both on opposite end
        {
            int fightsRight = n - right + 1;
            int countLeft = left - 1;
            int midCount = fightsRight - left - 1;
            int remainMidCount = right - fightsRight - 1;

             for(int survivorsLeft = 0;survivorsLeft <= countLeft;survivorsLeft++)
            {
                for(int survivorsMid = 0;survivorsMid <= midCount;survivorsMid++)
                {
                    int pos1 = survivorsLeft + 1;
                    int pos2 = pos1 + survivorsMid + (remainMidCount + 1)/2 + 1;

                    vector<int> tempResult = earliestAndLatest(nextRoundN,pos1,pos2);

                    minRound = min(minRound,1 + tempResult[0]);
                    maxRound = max(maxRound,1 + tempResult[1]);
                }
            }
        }
        return {minRound,maxRound};
    }
};