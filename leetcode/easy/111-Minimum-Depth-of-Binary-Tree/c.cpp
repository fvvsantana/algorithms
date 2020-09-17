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
        int currentDepth = 1;
        
        // find the depth of the leaf with minimum depth
        
        queue<TreeNode*> q;
        q.push(root);
        int currentLayerNodes = 1;
        int nextLayerNodes = 0;
        
        while(!q.empty()){
            // Assume that currentDepth is updated
            TreeNode* currentNode = q.front();
            q.pop();
            
            // Assume that there is at least 1 node in this layer
            currentLayerNodes--;
            
            if(!currentNode->left && !currentNode->right){
                return currentDepth;
                // 08:12
            }
            
            if(currentNode->left){
                q.push(currentNode->left);
                nextLayerNodes++;
            }
            
            if(currentNode->right){
                q.push(currentNode->right);
                nextLayerNodes++;
            }
            
            if(currentLayerNodes == 0){
                swap(currentLayerNodes, nextLayerNodes);
                currentDepth++;
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