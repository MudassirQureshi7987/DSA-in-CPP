/**
 * Implement a function to check if a list is a palindrome.
 *
 * Approach 1: Reverse the half the list and compare with other half.
 * Approach 2: Iterative Approach
 * 							- Push half the list in stack,
 * 							- Compare the rest of the list by popping off from the stack
 * Approach 3: Recursive Approach
 */

 #include <iostream>
 #include <stack>
 using namespace std;
 
 struct Node {
   char data;
   Node * next;
   Node ( char c ) : data{ c }, next{ nullptr } { }
 };
 
 /**
  * [insert helper routine to insert new node at head]
  * @param head [current head of the list]
  * @param c    [new node's data]
  */
 void insert( Node * & head, char c ) {
   Node * newNode = new Node(c);
   newNode->next = head;
   head = newNode;
 }
 
 /**
  * [printList = helper routine to print the list]
  * @param head [head of the list]
  */
 void printList( Node * head ) {
   while( head ) {
     std::cout << head->data << "-->";
     head = head->next;
   }
   std::cout << "nullptr" << std::endl;
 }
 
 
 /**
  * [reversedList helper routine to reverse a list]
  * @param  head [head of current list]
  * @return      [reversed list's head]
  */
 
 void reverse( Node * & head )
{
    if(head == NULL || (head && head->next == NULL))
    {
        return ;
    }

    Node* nextNode = NULL;
    Node* prev = NULL;

    while(head != NULL)
    {
        nextNode = head->next;
        head->next = prev;
        prev = head;
        head = nextNode;
    }

    head = prev;
}

/**
 * [isPallindromeIter1 - Iteratively determine if list is palindrome using reversing the list]
 * @param  head [Head node of the list]
 * @return      [True if list is palindrome, false if not]
 */
bool isPalindromeIter1( Node * head ) {
    if(head == NULL ||(head && head->next == NULL))
    {
        return true;
    }

    // step 1 figure out middle node
    Node* fast = head;
    Node* slow = head;
    Node* middleNode = NULL;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // in case of odd number of nodes
    if(fast && fast->next == NULL)
    {
      slow = slow->next;
    }

      //reverse the second half of the list
    reverse(slow);

    middleNode = slow;

    fast = head;

    while(fast && slow && fast->data == slow->data)
    {
      fast = fast->next;
      slow = slow->next;
    }

    // reverse the list again
    reverse(middleNode);

    if(fast == NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
}