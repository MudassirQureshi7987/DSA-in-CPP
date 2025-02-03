#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int convert(char c)
    {
        switch(c)
        {
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
            default:
                return 0;
        }

    }
    int romanToInt(string s) {
        int sum = 0;
        int i = 0; 
        int value = 0;

        while(i < s.length())
        {
            char c = s[i];
            value = convert(c);
            if(i+1 < s.length()){
            if((s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X' )) ||
               (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) ||
               (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M'))
               )
               {
                 value -= 2*value;
               }
            }
              
              sum += value;
              i++;
        }
        return sum;
    }
};