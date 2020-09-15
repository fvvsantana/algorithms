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
        stack<int> s;
        ListNode* currentNode = head;
        while(currentNode){
            s.push(currentNode->val);
            currentNode = currentNode->next;
        }
        
        // s = []
        // s = [5,4,3,2,1]
        ListNode* rev = nullptr;
        ListNode** last = &rev;
        
        while(!s.empty()){
            *last = new ListNode(s.top());
            s.pop();
            last = &((*last)->next);
        }
        // [val|next]-> [val|next]-> null
        
        return rev;
    }
};