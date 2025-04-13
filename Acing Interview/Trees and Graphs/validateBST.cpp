/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<iostream>
#include<stack>
using namespace std;


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