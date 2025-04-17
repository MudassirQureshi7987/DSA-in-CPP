

  struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



#include<iostream>
#include<stack>
using namespace std;

//Space optimized version of inorder,using inorder property of bst
class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            stack<TreeNode*> s;
            TreeNode* curr = root;
            TreeNode* prev = NULL;
            
            while(!s.empty() || curr != NULL)
            {
                while(curr != NULL)
                {
                    s.push(curr);
                    curr = curr->left;
                }
    
                curr = s.top();
                if(prev == NULL)
                {
                    prev = curr;
                }
                else
                {
                    if(curr->val <= prev->val)
                    {
                        return false;
                    }
                    prev = curr;
                }
                
                s.pop();
    
                curr = curr->right;
            }
    
            return true;
        }
    };


    #include <bits/stdc++.h> 

    // using min max,most optimized version
    template <typename T>
    class BinaryTreeNode 
    {
      public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };


bool solve(BinaryTreeNode<int>* root,int mini,int maxi)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->data > mini && root->data < maxi)
    {
        bool left = solve(root->left,mini,root->data);
        bool right = solve(root->right,root->data,maxi);

        return left && right;
    }
    else
    {
        return false;
    }
}
bool validateBST(BinaryTreeNode<int>* root) 
{
    return solve(root,INT_MIN,INT_MAX);
}