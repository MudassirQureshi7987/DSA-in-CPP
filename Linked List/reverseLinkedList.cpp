#include<iostream>
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

void insertAtHead(Node* &head,int data)
{
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;

}

void insertAtTail(Node* &tail,int data)
{
  Node* temp = new Node(data);
  tail->next = temp;
  tail = temp;
}

void print(Node* head)
{
    if(head==NULL)
    {
        cout<<"empty"<<endl;
        return;
    }
    Node* temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

void insertAtMiddle(Node* &tail,Node* &head,int position,int data)
{
  Node* temp = head;
  int count = 1;

  if(position==1)
  {
   
    insertAtHead(head,data);
    return ;
   
  }
 
  while(count<=position-1)
  {
    temp = temp->next;
    count++;
  }

  if(temp==NULL)
  {
    insertAtTail(tail,data);
    return;
  }

  Node* newNode = new Node(data);
  newNode->next = temp->next;
  temp->next = newNode;


}

void reverse(Node* &head,Node* &tail)
{

    Node* curr =  head;
    Node* prev = NULL;
    Node* aage = head->next;
   

    while(curr!= NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = aage;
    
        aage = aage ->next;
        cout<<"chal"<<endl;
        
    }
    tail = head;
    head =  curr;


}

int main()
{
    Node* temp = new Node(1);
    Node* head  = temp;
    Node*  tail = temp;
    insertAtHead(head,2);
    insertAtMiddle(tail,head,3,3);
    insertAtTail(tail,4);
    print(head);
    cout<< "head ->" <<head->data<<endl;
    cout<< "tail ->"<<tail->data<<endl;

    reverse(head,tail);
    print(head);


}