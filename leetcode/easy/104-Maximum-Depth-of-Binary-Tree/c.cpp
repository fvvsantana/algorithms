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
    int maxDepth(TreeNode* root) {
        // 07:38
        int mDepth = 0;
        
        dfs(root, 0, mDepth);
        
        return mDepth;
        
    }
    
    /*
    Perform dfs.
    Update max depth considering the currentDepth.
    currentDepth is actually the depth of the level before;
    */
    
    void dfs(TreeNode* root, int currentDepth, int& mDepth){
        if(!root){
            mDepth = max(mDepth, currentDepth);
            return;
        }
        dfs(root->left, currentDepth+1, mDepth);
        dfs(root->right, currentDepth+1, mDepth);
    }
    
};

/*
Read: 07:34 - 07:35
Solve: 07:35 - 07:38
Code: 07:38 - 07:53


Solution 1:


*/
