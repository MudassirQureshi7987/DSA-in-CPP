/**

 * You have a function "isSubstring" which checks whether a string is substring of another.
 * Given two strings s1 and s2, write code to check if s2 is a rotation of s1 using only one call to "isSubstring".
 *
 * Approach:
 * example s1 = "waterbottle", and s2 = "erbottlewat", clearly s2 is rotation of s1.
 * lets say s1 = xy ==> wat + erbottle
 * similarly s2 = yx ==> erbottle + wat
 * Therefore s1s1 = "waterbottlewaterbottle", clearly s2 is substring of s1s1
 * So if a string is formed by rotation of another string, it will always be substring of concatenated original string to itself.
 */

 #include <iostream>
 #include <string>
 using namespace std;


 bool isRotation(string s1,string s2)
 {
    int len1 = s1.length();
    int len2 = s2.length();

    if(len1 == 0 || len1 != len2)
    {
        return false;
    }

    string concateS1 = s1 + s1;
    /*
    If the substring is found, find returns the starting index (position) of the substring in the string.
    If the substring is not found, it returns std::string::npos, which is a constant representing an invalid position.
    */
    if(concateS1.find(s2) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
 }
 int main() {
    string s1, s2;
    cout << "Enter string 1 : ";
    cin >> s1;
    cout << "Enter string 2 : ";
    cin >> s2;
    if (isRotation(s1, s2)) {
        cout << "Yes! " << s2 << " is rotation of " << s1 << endl;
    } else {
        cout << "No! " << s2 << " is not a rotation of " << s1 << endl;
    }
    return 0;
}