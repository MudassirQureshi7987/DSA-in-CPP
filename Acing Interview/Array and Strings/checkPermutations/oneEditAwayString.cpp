/* 
 * Problem: There are three possible edits that can be performed on a string.
 * 1. Insert a char.
 * 2. Delete a char.
 * 3. Replace a char.
 *
 * Given two strings, determine if they are one or 0 edit away.
 *
 * Approach :
 * 1. Case when strings are of some length --> possible edit is replace.
 *    If there are more than one mismatch, return false
 *
 * 2. Case when One string is bigger than another
 *    Smaller string ------------> Bigger String
 *                     insert
 *                     delete
 *    smaller string <-----------  Bigger String
 *
 *    Idea is check if there are more than one mismatch discounting the already
 *    difference in the string. Therefore for first mismatch we do not move the pointer
 *    pointing to smaller string, and then expect it to match from next char of bigger
 *    string.
 */



 #include <iostream>
 #include <string>
 #include <cmath>
 using namespace std; 


bool oneEditAway(const string &str1,const string &str2)
{
    if(abs(str1.length()-str2.length()) > 1)
    {
        return false;
    }

    int len1 = str1.length();
    int len2 = str2.length();
    string smaller = len1 < len2 ? str1 : str2;
    string bigger = len1 < len2 ? str2 : str1;

    int i = 0;
    int j = 0;
    bool misMatchDone = false;

    while( i < smaller.length() && j < bigger.length())
    {
        if(smaller[i] != bigger[j])
        {
            if(misMatchDone)
            {
                return false;
            }
            misMatchDone = true;
            if(len1 == len2) // replace wali case cause in string with same length only replace possible
            {
                i++;
                
            }
        }
        else
        {  
            i++;        // move pointer in the smaller string on a match
        }
        j++;        // move pointer in the smaller string on a match
    }
    return true;
}

void translate( bool result, const std::string str1, const std::string str2 )
{
    if (result == true ) {
        std::cout << str1 << " and " << str2 << " are one edit away\n";
    } else {
        std::cout << str1 << " and " << str2 << " are not one edit away\n";
    }
}

int main()
{
    translate ( oneEditAway("pale", "ple"), "pale", "ple" );
    translate ( oneEditAway("pales", "pale"), "pales", "pale" );
    translate ( oneEditAway("pale", "pales"), "pale", "pales" );
    translate ( oneEditAway("pale", "bale"), "pale", "bale" );
    translate ( oneEditAway("pale", "bake"), "pale", "bake" );
    return 0;

}