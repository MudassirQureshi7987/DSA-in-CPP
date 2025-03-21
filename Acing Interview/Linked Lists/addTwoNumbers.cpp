/**

 * Problem 2.5 Sum lists
 * You have two numbers represented by linked list, where each node contains
 * a single digit. Digits are stored in reverse order.(1's digit is at the head)
 * Write a function that adds two such numbers and returns a number in similar
 * list format.
 * example:
 * 7-->1-->6 + 5-->9-->2 = 2-->1-->9
 * which is (617 + 295  = 912)
 * What if digits are not stored in reverse order(i.e 1's digit is at tail)
 * (6--1-->7) + (2-->9-->5) = (9-->1-->2)
 *
 * Approach:
 * We will solve the problem recursively and iteratively.
 * Add numbers at same digits place, store the 1's digit of the output in new list
 * and add carry in next place's addition.
 *
 * Finally, we will solve the follow up.
 */

 #include <iostream>

 struct Node {
   int data;
   Node * next;
   Node ( int d ) : data{ d }, next{ nullptr } { }
 };
 
 /**
  * [insert - insert a new node at head of the list]
  * @param head [head of the list]
  * @param data [new node's data]
  */
 void insert( Node * & head, int data ) {
   Node * newNode = new Node(data);
   newNode->next = head;
   head = newNode;
 }
 
 /**
  * [printList - print the list]
  * @param head [head of the list]
  */
 void printList( Node * head ) {
   while ( head ) {
     std::cout << head->data << "-->";
     head = head->next;
   }
   std::cout << "nullptr" << std::endl;
 }
 
 /**
  * [add_iterative iterative approach to add two given lists]
  * @param  list1
  * @param  list2
  * @return list3
  */
 Node * add_iterative( Node * list1, Node * list2 ) {
  if ( list1 == nullptr ) {
    return list2;
  }
  if ( list2 == nullptr ) {
    return list1;
  }

  // list3 will store result
  Node * list3 = nullptr;
  // for adding new nodes to tail of list3
  Node * list3Tail = nullptr;

  int value = 0, carry = 0;

  while( list1 || list2 ) {
    // add the values, if one of the list has already been traversed, add 0
    value = carry + (list1 ? list1->data : 0 ) + (list2 ? list2->data : 0);

    // get the new value and carry
    if ( value > 9 ) {
      carry = 1;
      value = value % 10;
    } else {
      carry = 0;
    }

    //new node
    Node * temp = new Node(value);

    //if this is the first node, populate the result, else add to the tail
    if ( list3 == nullptr ) {
      list3 = temp;
    } else {
      list3Tail->next = temp;
    }

    //make new tail
    list3Tail = temp;

    if (list1) {
      list1 = list1->next;
    }

    if (list2) {
      list2 = list2->next;
    }
  }

  if ( carry > 0 ) {
    list3Tail->next = new Node(carry);
  }
  return list3;
}

/**
 * [add_recursive - recursive addititon of two lists
 * @param  list1
 * @param  list2
 * @param  carry
 * @return list3
 */
Node* add_recursive(Node* list1,Node* list2,int carry)
{
  if(!list1 && !list2 && !carry)
  {
    return NULL;
  }

  int value = carry;

  if(list1)
  {
    value += list1->data;
  }
  if(list2)
  {
    value += list2->data;
  }

  Node* newNode = new Node(value%10);

  newNode->next = add_recursive((list1 ? list1->next:NULL),(list2?list2->next:NULL),value/10);

  return newNode;
}