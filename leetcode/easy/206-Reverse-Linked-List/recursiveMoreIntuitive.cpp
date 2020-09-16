/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    // This is the recursive version of the c.cpp
    
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* revHead = nullptr;
        rev(head, revHead);
        return revHead;
    }
    
    /*
    Assume head not null;
    Return the tail of the reverse list;
    Make revHead point to the head of the reverseList;
    */
    ListNode* rev(ListNode* head, ListNode*& revHead){
        if(!head->next){
            revHead = head;
            return head;
        }
        ListNode* tail = rev(head->next, revHead);
        head->next = nullptr;
        tail->next = head;
        return head;
    }
};


/*
Solve: 08:52 - 09:01
Code: 09:02

Solution 4:
1->2->3->4->5->NULL


5->4->3->2->NULL
1->NULL

1->NULL

*/