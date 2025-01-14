#include<iostream>
using namespace std;

class Node
{
  public:
  int data;
  Node* next;
  Node* prev;

  //constructor
  Node(int data)
  {
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }

  ~Node()
  {
    int value = this->data;

    if(this->next!=NULL)
    {
      delete next;
      next = NULL;
    }
    cout<<"Memory freed for the value "<<value<<endl;
  }
  
};

void print(Node* &head)
{

  Node* temp = head;
  cout<<"Printing Linked List"<<endl;

  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp = temp->next;
  }cout<<endl;
}

void insertAtHead(Node* &head,Node* &tail,int data)
{
   
    if(head==NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
       
    }
    else{
        
  Node* temp = new Node(data);
  temp->next = head;
  head->prev = temp;
  head = temp;
    }
}

void insertAtTail(Node* &head,Node* &tail,int data)
{
  
if(tail == NULL)
    {
      Node* temp = new Node(data);
      head = temp;
      tail = temp;    

    }
else{

  Node* temp = new Node(data);
  tail->next = temp;
  temp->prev = tail;
 // temp->next = NULL;     not mandatory cause next and prev is initialised to NULL at creation time
  tail = temp;
    }
}

void insertAtPosition(Node* &head,Node* &tail,int data,int position)
{
    
    if(position==1)
    {
        insertAtHead(head,tail,data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt<position-1)
    {
        temp = temp->next;
        cnt++;
    }

    if(temp->next==NULL)
    {
        insertAtTail(head,tail,data);
        return ;
    }

    Node* newNode = new Node(data);

    newNode->next = temp->next;
    newNode->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(int position,Node* &head,Node* &tail)
{
  
  if(position==1)
  {
   
    Node* temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    delete temp;
  }
  else{
    cout<<"Inside else"<<endl;
    int count = 1;
    Node* curr = head;
    Node* back = NULL;

    while(count<position)
    {
      back = curr;
      curr = curr->next;
      count++;
    }

    if(curr->next==NULL)
    {
      tail = back;
    }

    back->next = curr->next;
    curr->next = NULL;
    curr->prev = NULL;
    if(back->next!=NULL)
    {
    back->next->prev = back;
    }
    delete curr; 



  }
}

int main()
{
 
  Node* head = NULL;
  Node* tail = NULL;
  print(head);

  insertAtHead(head,tail,11);
  //cout<<"Head "<<head->data<<endl;

  insertAtTail(head,tail,12);
  insertAtTail(head,tail,14);
  print(head);
//  cout<<"Tail "<<tail->data<<endl;
   

   insertAtPosition(head,tail,23,3);
   print(head);

   deleteNode(4,head,tail);
   print(head);
   cout<<"Head="<<head->data<<endl;
   cout<<"Tail="<<tail->data<<endl;
}
