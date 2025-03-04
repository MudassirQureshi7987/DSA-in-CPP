#include <iostream>
#include <cstring>

/*
 * Function : urlify
 * Args     : string long enough to accomodate extra chars + true len 
 * Return   : void (in place transformation of string)
 */


void urlify(char *str,int truelen)
{
    int numOfSpaces = 0;
    int i = 0,j = 0;
    for(int i = truelen-1;i >= 0;i--)
    {
        if(str[i] == ' ')
        {
            numOfSpaces++;
        }
    }

    int extendedLen = truelen + 2*numOfSpaces;
    i = extendedLen - 1;
    for(j = truelen-1;j >= 0;j--)
    {
        if(str[j] == ' ')
        {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
        else
        {
            str[i--] = str[j];
        }
    }
}


int main()
{
    char str[] = "Mr John Smith    ";                       //String with extended length ( true length + 2* spaces)
    std::cout << "Actual string   : " << str << std::endl;
    urlify(str, 13);                                        //Length of "Mr John Smith" = 13
    std::cout << "URLified string : " << str << std::endl;
    return 0;
}