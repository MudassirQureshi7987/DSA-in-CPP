#include<iostream>
using namespace std;

class TreeNode
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }


    int getHeight(TreeNode* root)
    {
        if(root == NULL)
        {
            return -1;
        }

        return max(getHeight(root->left),getHeight(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }

        int heightDiff = abs(getHeight(root->left) - getHeight(root->right));

        if(heightDiff > 1)
        {
            return false;
        }
        else
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
};

class TreeNode
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }


    int checkHeight(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int leftTree = checkHeight(root->left);

        if(leftTree == -1)
        {
            return -1;
        }

        int rightTree = checkHeight(root->right);

        if(rightTree == -1)
        {
            return -1;
        }

        if(abs(leftTree - rightTree) > 1)
        {
            return -1;
        }
        else
        {
            return  max(leftTree,rightTree) + 1;
        }
    }
    bool isBalanced(TreeNode* root)
    {
        return checkHeight(root) != -1;
    }
};
