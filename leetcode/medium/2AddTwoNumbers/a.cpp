/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		
		ListNode* out;
        ListNode** currentNode = &out;
        int go = 0;
        
        // foo (ListNode* l1) (ListNode* l2) (int go) (ListNode** currentNode)
        // Add two lists and put the sum into "out". Also add go as previous value.
        while(l1 && l2){

			// add
			int aux = go + (l1->val) + (l2->val);
			
            // update go and aux
			if(aux > 9){
				go = 1;
				aux -= 10;
			}else{
				go = 0;
			}
            
			// create node
			ListNode* newNode = new ListNode(aux);
            *currentNode = newNode;
            currentNode = &(newNode->next);
            
            l1 = l1->next;
            l2 = l2->next;
		}
        
        ListNode* tail = (ListNode*) ((long) l1 + (long) l2);
        
        // foo (ListNode** currentNode) (int go) (ListNode* tail)
        // Add go through the list and expand the currentNode's list
        while(tail){
            int aux = go + (tail->val);
            
            // update go and aux
			if(aux > 9){
				go = 1;
				aux -= 10;
			}else{
				go = 0;
			}
            
            // create node
			ListNode* newNode = new ListNode(aux);
            *currentNode = newNode;
            currentNode = &(newNode->next);
            
            tail = tail->next;
        }
        
        // Add go to the end
        if(go){
            *currentNode = new ListNode(go);
        }
        
        return out;

    }
};