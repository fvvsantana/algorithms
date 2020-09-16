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
    
    //08h15
    
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        return rev(head);
    }
    
    /*
        Supose that head points to a not-null node;
        Reverse the list starting at head;
        Return a pointer to the head of the reversed list;
        Point the tail of the reversed list to lastNode;
    */
    
    ListNode* rev(ListNode* head, ListNode* lastNode = nullptr){
        if(!(head->next)) {
            head->next = lastNode;
            return head;
        }
        ListNode* ans = rev(head->next, head);
        head->next = lastNode;
        return ans;
    }
    
};

/*
Read:
Solve: 7:56 - 
Code:  08:15 - 08:28
Testing: 08:28 - 08:39

Solution 3:
1->2->3->4->5->NULL
NULL<-1<-2<-3<-4<-5

5->4->3->2->NULL
1->NULL

1->NULL


*/