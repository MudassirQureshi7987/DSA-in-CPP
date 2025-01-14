#include<iostream>
#include<map>
using namespace std;

class Node
{
  public:
  int data;
  Node* next;

  public:
 Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }

   //destructor
  ~Node()
  {
    int  value = this->data;

    if(this->next!=NULL)
    {
      delete next;
      this->next = NULL;
    }
    cout<<"Memory freed for value "<<value<<endl;
   
  }
};

bool isCircular(Node* head)
{
  //NULL list
  if(head==NULL)
  {
    return true;
  }

  Node* temp = head->next;

  while(temp!=NULL && temp!=head)
  {
    temp = temp->next;

  }

  if(temp==NULL)
  {
    return false;
  }
  else{
    return true;
  }
}

void insertNode(Node* &tail,int value,int data)
{
  if(tail==NULL)
  {
    Node* temp = new Node(data);
    tail = temp;
    temp->next = temp;
  }
  else{
    Node* temp = tail;
   
    while(temp->data!=value)
    {
      temp = temp->next;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;

    
    
  }
}

void deleteNode(Node* &tail,int value)
{
  Node* prev = tail;
  Node* curr = prev->next;

  while(curr->data!=value)
  {
    prev = curr;
    curr = curr->next;
  }
  //edge case for 1 node only
  if(curr == prev)
  {
    tail = NULL;
  }

  prev->next = curr->next;
  if(tail==curr)
  {
    tail = prev;
  }
  curr->next = NULL;
  delete curr;

 

}

void print(Node* tail)
{
  Node* temp = tail;

  if(tail==NULL)
  {
    cout<<"List is empty"<<endl;
  }

  do
  {
    cout<<tail->data<<" ";
    tail = tail->next;
  } while (tail != temp);
  
  cout<<endl;
  cout<<tail->data<<endl;
}

bool detectLoop(Node* head)
{
  if(head==NULL)
  {
    return false;
  }

  map<Node*,bool> visited;

  Node* temp =  head;

  while(temp!=NULL)
  {
    if(visited[temp] == true)
    {
      return true;
    }
    visited[temp] = true;
    temp = temp->next;
  }

  return false;


}

int main()
{
  Node* tail = NULL;
  insertNode(tail,2,1);
  print(tail);
 insertNode(tail,1,2);
  print(tail);
  insertNode(tail,1,3);
  print(tail);
  insertNode(tail,1,5);

 // deleteNode(tail,2);
  print(tail);

  /*if(isCircular(tail))
  {
      cout<<"Linked list is circular"<<endl;
  }
  else{
    cout<<"Linked list is not circular bro"<<endl;
  }*/


}
