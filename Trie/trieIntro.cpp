#include<iostream>
using namespace std;

class TrieNode
{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i = 0;i < 26;i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    public:
        TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string word)
    {
        // base case
        if(word.length() == 0)
        {
            root->isTerminal = true;
            return ;
        }

        // assuming that word is in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            // present
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root,string word)
    {
        //base case
        if(word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else 
        {
            return false;
        }

        //RECURSION
        return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root,word);
    }

    void removeUtil(TrieNode* root,string word)
    {
        //base case
        if(word.length() == 0)
        {
            root->isTerminal = false;
            return ;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return ;
        }

        removeUtil(child,word.substr(1));

        // Optional: Cleanup - if the child is not terminal and has no children, delete it.
        if(child->isTerminal != true)
        {
            bool hasChild = false;
            for(int i = 0;i < 26;i++)
            {
                if(root->children[i] != NULL )
                {
                    hasChild = true;
                    break;
                }
            }

            if(hasChild != true)
            {
                delete child;
                root->children[index] = NULL;
            }
        }
    }

    void removeWord(string word)
    {
        removeUtil(root,word);
    }
};

int main()
{
    Trie* t = new Trie();

    t->insertWord("WORD");
    t->insertWord("WOR");
    t->insertWord("TIME");
    t->insertWord("DO");
    t->removeWord("WORD");
    

    if(t->searchWord("WORD"))
    {
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }
    return 0;
}