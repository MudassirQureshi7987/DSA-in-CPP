#include<iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};


bool floydCycleDetectionAlgorithm(Node* head)
{
    cout<<"buck"<<endl;
    if(head==NULL)
    {   
        cout<<"Kahe ka he loop hoga re tu"<<endl;
        return false;
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
            cout<<"Meet at "<<fast->data<<endl;
            return true;
        }
       

    }

    return false;




}
int main() {
  
    // Create a linked list: 10 -> 15 -> 4 -> 20
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(4);
    head->next->next->next = new Node(20);

    head->next = head;

   

    if ( floydCycleDetectionAlgorithm(head))
       cout<<"Loop loop"<<endl;
    else
       cout<<"Chale ja"<<endl;

    return 0;
}