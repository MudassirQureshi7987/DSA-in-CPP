class Solution {
    private:
    static bool dupPresent(string s)
    {
        for(int i = 0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
            {
                return true;
            }
        }
        return false;
    }
public:
    string removeDuplicates(string s) {
      
       while(dupPresent(s)==true && s.length()!=0)
       {
        for(int i = 0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
            {
            s.erase(s.begin()+i,s.begin()+i);
            }
        }
       
        }
        return s;
       }

};

int main()
{
    
}