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

void deleteAtPosition(int position,Node* &head,Node* &tail)
{
  if(position==1)
  {
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
  }
  else{
    //deleting in the middle or at last
    int count = 1;
    Node* curr = head;
    Node* prev = NULL;

    while(count<position)
    {
      prev = curr;
      curr = curr->next;
      count++;
    }

    if(curr->next==NULL)
    {
      tail = prev;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
  }
}

void deleteValue(int value,Node* &head,Node* &tail)
{
   Node* temp = head;
   
   if(head->data==value)
   {
     head =  head->next;
     temp->next = NULL;
     delete temp;
   }

   Node* curr = head->next;
   Node* prev = head;

   while(curr->data!=value)
   {
    prev = curr;
    curr = curr->next;
   }

    if(curr->next==NULL)
    {
      tail = prev;
    }



   prev->next = curr->next;
   curr->next = NULL;
   delete curr;
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

Node* floydCycleDetectionAlgorithm(Node* head)
{
   
    if(head==NULL)
    {   
        cout<<"Kahe ka he loop hoga re tu"<<endl;
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;


    while(fast!=NULL)
    {
       
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL)
        {
            fast = fast->next;
        }
        if(fast==slow)
        {
           
            return slow; 
        }
       

    }

    return NULL;




}

Node* getStartingNode(Node* head)
{
  if(head==NULL)
  {
    return NULL;
  }

  Node* intersection = floydCycleDetectionAlgorithm(head);

  if(intersection==NULL)
  {
    return NULL;
  }

  Node* slow = head;

  while(slow!=intersection)
  {
    intersection = intersection->next;
    slow = slow->next;
  }

  return slow;
}

void insertAtValue(Node* &head,Node* &tail,int d,int value)
{
  Node* temp = head;

  while(temp->data != value)
  {
    temp = temp ->next;
  }

  
    Node* newe = new Node(d);
    newe->next = temp->next;
    temp->next = newe;

    if(newe->next == NULL)
    {
      tail = newe;
    }
    

    
  


 
}

void removeLoop(Node* head)
{
  if(head==NULL)
  {
    return ;
  }

  Node* startingNode = getStartingNode(head);
  Node* temp = startingNode;

  while(temp->next!=startingNode){
    temp = temp->next;
  }

  temp->next = NULL;
}

/*
int main()
{ 
  // created a new node
  Node* node1 = new Node(10);
 // cout<<node1->data<<endl;
  // cout<<node1->next<<endl;

  //giving first address to head

  Node* head = node1;
  Node* tail = node1;
  cout<<"Head before "<<head<<endl;
  print(head);

  //insering at head
 // insertAtHead(head,12);
 // insertAtHead(head,43);
//  print(head);
  cout<<"Head after "<<head<<endl;

  //inserting at tail
  cout<<endl;
  cout<<"Insert at Tail"<<endl;
  insertAtTail(tail,12);
  insertAtTail(tail,43);
  print(node1);


   insertAtMiddle(tail,head,1,22);
   insertAtMiddle(tail,head,3,13);
   print(head);

   tail->next = head->next;

   cout<<head->data<<endl;
   cout<<tail->data<<endl;



  // deleteAtPosition(4,head,tail);
   //print(head);
  

   

   /* if(isCircular(tail))
  {
      cout<<"Linked list is circular"<<endl;
  }
  else{
    cout<<"Linked list is not circular bro"<<endl;
  }   */

/* if(detectLoop(head))
 {
  cout<<"Loop is present"<<endl;
 }
 else
 {
  cout<<"Loop is absent"<<endl;
 } 

Node* ans = floydCycleDetectionAlgorithm(head);
cout<<"They meet at "<<ans->data<<endl;

Node* meet = getStartingNode(head);
cout<<"Starting node is "<<meet->data<<endl;
removeLoop(head);
print(head);

} 
*/

int main()
{
   Node* node1 = new Node(10); 
   Node* head = node1;
   Node* tail = node1;

   insertAtHead(head,11);
   insertAtTail(tail,12);

   print(head);

   insertAtValue(head,tail,14,10);

   print(head);

   insertAtValue(head,tail,15,11);

   print(head);

   insertAtValue(head,tail,16,12);

   print(head);

   cout<<"Head "<<head->data<<endl;
   cout<<"Tail "<<tail->data<<endl;
}


//linked list dun dana dun dan