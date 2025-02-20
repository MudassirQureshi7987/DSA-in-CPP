 #include<iostream>
 using namespace std;
 
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    void insertAtTail(ListNode* &list,ListNode* &tail,int data)
    {
        if(list == NULL)
        {
            ListNode* temp = new ListNode(data);
            list = temp;
            tail = temp;
            return ;
        }

        ListNode* temp = new ListNode(data);
        temp->next = tail->next;
        tail->next = temp;

        tail = temp;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list = NULL;
        ListNode* tail = NULL;
        while(list1 != NULL && list2 != NULL)
        {
        if(list1 -> val  < list2 ->val)
        {
            insertAtTail(list,tail,list1->val);
            list1 = list1->next;
        }
        else
        {
            insertAtTail(list,tail,list2->val);
            list2 = list2->next;
        }

        }

        while(list1 != NULL)
        {
            insertAtTail(list,tail,list1->val);
            list1 = list1->next;
        }

        while(list2 != NULL)
        {
            insertAtTail(list,tail,list2->val);
            list2 = list2 ->next;

        }
        return list;
    }
};