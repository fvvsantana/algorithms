class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        return 0;
    }
};

/*
Read: 09:19 - 09:22
Solve: 09:23 - 09-29
Code:

Solution 1:
Call recursion to the whole matrix.
Dfs to find the largest connected graph.
Use the input matrix, mark visited nodes as -1.
Need global maxArea, local currentArea.
Check if node is -1 before calling recursion.

Complexity:
Time: O(m*n)
Space: O(m*n)

*/