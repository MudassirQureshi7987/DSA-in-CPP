/**
 * Cracking the coding interview edition 6
 * Problem 2.7 Intersection
 * Given two linked lists, if they both intersect at some point.
 * Find out the intersecting point else return nullptr.
 * Intersection is defined based on reference not value.
 */

 #include <iostream>
 #include <cmath>
 using namespace std;
 
 struct Node {
   int data;
   Node * next;
   Node( int d ) : data{ d }, next{ nullptr } { }
 };
 
 /**
  * [printList Helper routine to print list]
  * @param head [head of the list]
  */
 void printList( Node * head )
 {
   while( head ) {
     std::cout << head->data << "-->";
     head = head->next;
   }
   std::cout << "NULL" << std::endl;
 }

 /**
 * [intersectionPoint Returns the point of intersection of two lists]
 * @param  head1 [ head of list 1 ]
 * @param  head2 [ head of list 2 ]
 * @return       [ Intersecting node, if lists intersect, else nullptr]
 */

 int listLen(Node* head)
 {
    int cnt = 0;
    while(head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
 }
Node * intersectionPoint( Node * head1, Node * head2 )
{
    int len1 = listLen(head1);
    int len2 = listLen(head2);

    Node* ptr1 = (len1 > len2)?head1:head2;
    Node* ptr2 = (len1 > len2)?head2:head1;

    int diff = abs(len1 - len2);
    int i = 0;
    while(i < diff && ptr1)
    {
        ptr1 = ptr1->next;
        i++;
    }

     //Now we have equal nodes to travel on both the nodes
  // traversing and comparing the pointers.
  while(ptr1 && ptr2)
  {
    if(ptr1 == ptr2)
    {
        return ptr1;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return NULL;
}