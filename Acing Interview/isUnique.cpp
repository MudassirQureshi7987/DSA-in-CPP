#include <string>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

bool isUniqueChars(const string &str)
{
    if(str.length() > 128)
    {
        return false;
    }

    vector<bool> char_set(128);
    for(int i = 0;i < str.length();i++)
    {
        int val = str[i];
        if(char_set[val])
        {
            return false;
        }
        char_set[val] = true;
    }
    return true;
}

bool isUniqueChars_bitvector(const string &str) {
	//Reduce space usage by a factor of 8 using bitvector. 
	//Each boolean otherwise occupies a size of 8 bits.
	bitset<256> bits(0);
	for(int i = 0; i < str.length(); i++) {
		int val = str[i];
		if(bits.test(val) > 0) {  // if(bits.test(val))   this will also work
			return false;
		}
		bits.set(val);
	}
	return true;
}


// without using any extra space
bool isUniqueChars_noDS(const string &str) {
	for(int i = 0; i < str.length()-1; i++) {
		for(int j = i+1; j < str.length(); j++) {
			if(str[i] == str[j]) {
				return false;
			}
		}
	}
	return true;	
}