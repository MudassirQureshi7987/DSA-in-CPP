/**

 *  Problem 2.4 Partition:
 *  Write code to partition linked list around a value x, such that
 *  nodes less than x come before all the nodes greater than or equal to x.
 *  If x is in the list, the values of x only need to be after the elements less
 *  than x.
 *  Example
 *  3-->5-->8-->5-->10-->2-->1 (x = 5)
 *  3-->1-->2-->10-->5-->5-->8
 *
 *  Approach:
 *  Start with first node, and add every thing bigger or equal to x at tail
 *  and smaller values at head.
 */

 #include <iostream>
 #include <random>
 
 struct Node {
   int data;
   Node * next;
   Node( int d ) : data{ d }, next{ nullptr } { }
 };
 
 void insert( Node * & head, int data ) {
   Node * newNode = new Node(data);
   if ( head == nullptr ) {
     head = newNode;
   } else {
     Node * curr = head;
     while( curr->next ) {
       curr = curr->next;
     }
     curr->next = newNode;
   }
 }
 
 void printList( Node * head ) {
   while ( head ) {
     std::cout << head->data << "-->";
     head = head->next;
   }
   std::cout << "nullptr" << std::endl;
 }

 Node* partition(Node* listhead,int x)
 {
    Node* lessHead = NULL;
    Node* lessTail = NULL;
    Node* greatHead = NULL;
    Node* greatTail = NULL;

    Node* curr = listhead;

    while(curr != NULL)
    {
      Node* nextNode = curr->next;
      curr->next = NULL;

      if(curr->data < x)
      {
        if(lessHead == NULL)
        {
          lessHead = curr;
          lessTail = curr;
        }
        else 
        {
          lessTail->next = curr;
          lessTail = curr;
        }
    }
    else
    {
      if(greatHead == NULL)
      {
        greatHead = curr;
        greatTail = curr;
      }
      else
      {
        greatTail->next = curr;
        greatTail = curr;
      }
    }
    curr = nextNode;
  }

  if(lessHead == NULL)
  {
    return greatHead;
  }

  lessTail->next = greatHead;
  return lessHead;
}



int main()
 {
    Node * head = nullptr;
    for ( int i = 0; i < 10; ++i ) {
          insert(head, rand() % 9);
      }
    std::cout << "List before partition around 5:\n";
    printList(head);
    std::cout << "List after partition around 5:\n";
    printList(partition(head, 5));
    return 0;
  }