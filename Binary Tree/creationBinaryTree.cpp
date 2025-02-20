#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root)
{
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout<<"Enter data for  inserting in left of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for  inserting in right"<<root->data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void inorder(node* root)
{
    if(root == NULL)
        return ;

    inorder(root->left);
    cout<< root->data<<" ";
    inorder(root->right);
}

void inorderIterative(node* root)
{
    stack<node*> s;
    node* curr = root;

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

void preorder(node* root)
{
    if(root == NULL)
        return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)
{
    if(root == NULL)
        return ;
     
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            //level khatam ho gaya hai or us level ke sabhi childs queue mai aa chuke hai
            cout<<endl;

            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";

            if(temp->left)   // if still have some child nodes
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelOrderTraversal(node* root)
{
    stack<node*> s;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* curr = q.front();
        q.pop();
        s.push(curr);

        if(curr == NULL)
        {
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if(curr->right)
            {
                q.push(curr->right);
            }
    
            if(curr->left)
            {
                q.push(curr->left);
            }
        }

    }

    while(!s.empty())
    {
        node* curr = s.top();
        if(curr == NULL)
        {
            cout<<endl;
        }
        else
        {
            cout<< curr->data<<" ";
        }
       
        s.pop();
    }
}

int main()
 {
    node* root = NULL;

    root = buildTree(root);
    levelOrderTraversal(root);

        // Create hard coded tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5 
    // node *root = new node(1); 
    // root->left = new node(2); 
    // root->right = new node(3); 
    // root->left->left = new node(4); 
    // root->left->right = new node(5); 

    reverseLevelOrderTraversal(root); 

    cout<<"Inorder : ";
    inorder(root);

    cout<<endl<<"Preorder: ";
    preorder(root);

    cout<<endl<<"Postorder:";
    postorder(root);

    cout<<"Inorder : ";
    inorderIterative(root);
 }