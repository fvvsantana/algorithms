/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        // 08:01
        if(!root) return 0;
        int currentDepth;
        
        // find the depth of the leaf with minimum depth
        
        queue<pair<TreeNode*,int>> q;
        q.push(pair<TreeNode*,int>(root, 1));
        
        while(!q.empty()){
            // Assume that currentDepth is updated
            pair<TreeNode*,int> p = q.front();
            TreeNode* currentNode = p.first;
            currentDepth = p.second;
            q.pop();
            
            if(!currentNode->left && !currentNode->right){
                return currentDepth;
                // 08:12
            }
            
            if(currentNode->left){
                q.push(pair<TreeNode*,int>(currentNode->left, currentDepth+1));
            }
            
            if(currentNode->right){
                q.push(pair<TreeNode*,int>(currentNode->right, currentDepth+1));
            }
            
        }
        return -1;
        
    }
};

/*
Read: 07:57 - 07:58
Solve: 07:59 - 08:01
Code: 08:01 -!08:17(solved another problem) 

Solution 1:
BFS
When I find a leaf, I'll stop



1 2    3
3 9 20 15 7

Complexity:
Time: O(n)
Space: O(n)


*/