
// The node with the smallest value that is larger than the given node's value.

// It is the next node that would be visited in an inorder traversal.


    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


#include<stack>
#include<iostream>
using namespace std;
BinaryTreeNode<int>* leftMost(BinaryTreeNode<int>* node)
{
    while(node->left)
    {
        node = node->left;
    }
    return node;
}
BinaryTreeNode<int> *inorderSuccesor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node)
{
    if(node->right)
    {
        return leftMost(node->right);
    }

    stack<BinaryTreeNode<int>*> st;
    BinaryTreeNode<int>* curr = root;
    BinaryTreeNode<int>* prev = NULL;

    while(curr != NULL || !st.empty())
    {
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }


        curr = st.top();
        st.pop();
        if(prev == node)
        {
            return curr;
        }

        prev = curr;

    
        curr = curr->right;
        
    }

    
    return NULL;
}

class TreeNode
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;

        TreeNode(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
            parent = NULL;
        }
};

TreeNode* mostLeft(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}
TreeNode* findSuccessor(TreeNode* root) {
    // If there is a right subtree, the successor is the smallest node in that subtree.
    if (root->right != nullptr) {
        return mostLeft(root->right);
    }
    
    // Otherwise, the successor is one of the ancestors.
    TreeNode* child = root;
    TreeNode* ancestor = root->parent;
    
    // Climb up the tree until we find a node which is a left child of its parent.
    // The parent in that situation is the inorder successor.
    while (ancestor != nullptr && ancestor->right == child) {
        child = ancestor;
        ancestor = child->parent;
    }
    
    return ancestor;
}