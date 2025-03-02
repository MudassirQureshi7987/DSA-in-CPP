#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
        Node(int x) {
            data = x;
            left = right = nullptr;
        }
    };
    void fillPreorder(Node* root,vector<int> &inorder,int &i)
    {
        if(root == NULL)
        {
            return ;
        }

        root->data = inorder[i++];
        fillPreorder(root->left,inorder,i);
        fillPreorder(root->right,inorder,i);
    }
void convertBSTtoMinHeap(Node* root)
{
    vector<int> inorder = {1,2,3,4,5,6,7};

    int index = 0;

    fillPreorder(root,inorder,index);
}

void preorderPrint(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " "; 
    preorderPrint(root->left); 
    preorderPrint(root->right); 
}

int main() {
  
    // Constructing the Binary Search Tree (BST)
    //          4
    //        /   \
    //       2     6
    //      / \   / \
    //     1   3 5   7
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertBSTtoMinHeap(root);
    preorderPrint(root);

    return 0;
}