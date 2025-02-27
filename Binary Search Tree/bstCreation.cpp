#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root,int data)
{
    //base case
    if(root==NULL)
    {
        root = new Node(data);
        return root;
    }

    if(data < root->data)
    {
        root->left = insertIntoBST(root->left,data);
    }
    else{
        root->right = insertIntoBST(root->right,data);
    }

    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

Node* minValue(Node* root)
{
    Node* temp = root;

    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();

        if(front == NULL)
        {
            //level khatam hua hai
            cout<<endl;

            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";

            if(front->left)
            {
                q.push(front->left);
            }

            if(front->right)
            {
                q.push(front->right);
            }
        }
    }
}

void inorderIterative(Node* root)
{
    stack<Node*> s;
    Node* curr = root;

    while( curr != NULL || !s.empty())
    {
        while(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        //at this  point curr is NULL
        curr = s.top();
        cout<<s.top()->data<<" ";
        s.pop();

        curr = curr->right;
    }
}

void preorder(Node* root)
{
    if(root == NULL)
        return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL)
        return ;
     
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

Node* inorderSuccessor(Node* root,int x)
{
    Node* successor = NULL;

    while(root != NULL)
    {
        if(x >= root->data)
        {
            root = root->right;
        }
        else{
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

Node* inorderPredecessor(Node* root,int x)
{
    Node* predecessor = NULL;

    while( root != NULL)
    {
        if(x > root->data)
        {
            predecessor = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return predecessor;
}

Node* deleteFromNode(Node* root,int val)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == val) // mil gaya
    {
        // 0 child wali case
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child hai bas

        //left child hai
        if(root->left != NULL && root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child hai
        if(root->left == NULL && root->right != NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child hai bhai

        if(root->left != NULL && root->right != NULL)
        {
            Node* temp = minValue(root->right);
            root->data = temp->data;
            root->right = deleteFromNode(root->right,temp->data);
            return root;

        }
    }
    else  // dhundho dhundho
    {
        if(root->data > val)
        {
            root->left = deleteFromNode(root->left,val);
        }
        else
        {
            root->right = deleteFromNode(root->right,val);
        }
    }
}
int main()
{
    Node* root = NULL;
    
    cout<<"Enter data to create BST:"<<endl;
    takeInput(root);

    levelOrderTraversal(root);

    cout<<"Minimum value is "<<minValue(root)->data<<endl;
    inorderIterative(root);
    cout<<endl<<"Successor of 8 is "<<inorderSuccessor(root,8)->data<<endl;
    cout<<"Predecessor of 3 is "<<inorderPredecessor(root,3)->data<<endl;

    root = deleteFromNode(root,7);
    levelOrderTraversal(root);
    inorderIterative(root);


    return 0;
}