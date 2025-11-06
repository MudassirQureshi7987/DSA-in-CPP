
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

bool arePermutation(string str1,string str2)
{
    // Get lengths of both strings
    int n1 = str1.length();
    int n2 = str2.length();

    // If length of both strings is not same, then they
    // cannot be anagram
    if (n1 != n2)
      return false;

    // Sort both strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    // Compare sorted strings
    for (int i = 0; i < n1;  i++)
       if (str1[i] != str2[i])
         return false;

    return true;
}

bool arePermutation_2(const string &str1, const string &str2) {
  if(str1.length() != str2.length()) 
    return false;

  // storing based on ASCII
  int count[256]={0};

  // setting frequency of the first string
  for(int i = 0; i < str1.length(); i++) {
    int val = str1[i];
    count[val]++;
  }

  // chceking if the same frequency is there in other string 
  // by simply decrementing on finding a char
  // if any character goes less than zero than that means
  // that second string has more of that character
  for(int i = 0; i < str2.length(); i++) {
    int val = str2[i];
    count[val]--;
    if(count[val]<0) 
      return false;
  }
  return true;
}