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
    ListNode* reverseList(ListNode* head) {
        
        //7h36
        
        if(!head || !(head->next)) return head;
        
        ListNode* lastNode = NULL;
        ListNode* nextNode = head->next;
        
        while(nextNode){
            head->next = lastNode;
            
            lastNode = head;
            head = nextNode;
            nextNode = nextNode->next;
        }
        head->next = lastNode;
        
        return head;
        // 7:50
    }
    
    
};

/*
Read:
Solve: 7h34 - 7h36
Code:  7h36 - 7h50

Solution 2:
1->2->3->4->5->NULL
NULL<-1<-2<-3<-4<-5 (head)

1->2->NULL
NULL<-1 2->NULL
NULL<-1<-2

Complexity:
Time: O(n)
Space: O(1) (without input)

*/