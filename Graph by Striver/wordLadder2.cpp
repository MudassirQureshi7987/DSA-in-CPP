#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
    public:
      vector<vector<string>> findSequences(string beginWord, string endWord,
                                           vector<string>& wordList) {
          // code here
          unordered_set<string> st(wordList.begin(),wordList.end());
          queue<vector<string>> q;
          vector<vector<string>> ans;
          q.push({beginWord});
          vector<string> usedOnLevel;
          usedOnLevel.push_back(beginWord);
          int level = 0;
          while(!q.empty())
          {
              vector<string> vec = q.front();
              q.pop();
  
              if(vec.size() > level)
              {
                  level++;
                  for(auto it:usedOnLevel)
                  {
                      st.erase(it);
                  }
              }
  
              string word = vec.back();
  
              if(word == endWord)
              {
                  if(ans.size() == 0)
                  {
                      ans.push_back(vec);
                  }
                  else if(ans[0].size() == vec.size())
                  {
                      ans.push_back(vec);
                  }
              }
              for(int i = 0;i < word.size();i++)
              {
                  char original = word[i];
  
                  for(char ch = 'a';ch <= 'z';ch++)
                  {
                      word[i] = ch;
                      if(st.count(word) > 0)
                      {
                          vec.push_back(word);
                          q.push(vec);
                          usedOnLevel.push_back(word);
                          vec.pop_back();
                      }
                      
                  }
                  word[i] = original;
              }
          }
          return ans;
      }
  };

  class Solution {
    unordered_map<string,int> mpp;
    vector<vector<string>> ans;
    string b;
public:
    void dfs(string word,vector<string> &seq)
    {
        if(word == b)
        {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return ;
        }
            int steps = mpp[word];
            int sz = b.size();
            for(int i = 0;i < sz;i++)
            {
                char original = word[i];

                for(char c = 'a';c <= 'z';c++)
                {
                    word[i] = c;
                    if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
                    {
                        seq.push_back(word);
                        dfs(word,seq);
                        seq.pop_back();
                    }
                }
                word[i] = original;
            }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b = beginWord;
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);
        int sz = beginWord.size();
        while(!q.empty())
        {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if(word == endWord) break;
            for(int i = 0;i < sz;i++)
            {
                char original = word[i];

                for(char c = 'a';c <= 'z';c++)
                {
                    word[i] = c;
                    if(st.count(word))
                    {
                        mpp[word] = steps+1;
                        q.push(word);
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        if(mpp.find(endWord) != mpp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};