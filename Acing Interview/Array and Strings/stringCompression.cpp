/*

 * Problem 1-6 Implement a method to perform basic string compression.
 * Example string aabcccccaaa should be compressed to a2b1c5a3,
 * however if compressed string is bigger than original string, return original string
 */

 #include <iostream>
 #include <string>
 using namespace std;

 string compress(string str)
 {
    if(str.length() < 2)
    {
        return str;
    }

    string ans = "";
    int count = 0;

    for(int i = 0;i < str.length();i++)
    {
        count++;

        if(str[i] != str[i+1])
        {
            ans += str[i] + to_string(count);
            count = 0;
        }
    }
    if(ans.length() < str.length())
    {
        return ans;
    }
    else
    {
        return str;
    }
 }

 int main()
{
	std::string str, out;
	std::cout << "Enter a string:\n";
	std::cin >> str;
	out = compress(str);
	if (str.compare(out)) {
		std::cout << str << " can be compressed to " << out << std::endl;
	} else {
		std::cout << str << " can not be compressed\n";
	}
	return 0;
}