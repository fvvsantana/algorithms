class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 16:24
        int n = nums.size();
        vector<vector<int>> sols(n, vector<int>(2));
        sols.at(0).at(0) = nums.at(0);
        sols.at(0).at(1) = nums.at(0);
        
        for(int i = 1; i < n; i++){
            sols.at(i).at(0) = max(sols.at(i-1).at(0), sols.at(i-1).at(1));
            sols.at(i).at(1) = max(nums.at(i), sols.at(i-1).at(1) + nums.at(i));
        }
        
        return max(sols.at(n-1).at(0), sols.at(n-1).at(1));
        // 16:31
        
    }
};
/*
Final solution: max(S(n-1, 0), S(n-1, 1))

if p = 0:
    S(i, p) = max(S(i-1, 0), S(i-1, 1))
else:
    S(i, p) = max(nums[i], S(i-1, 1) + nums[i])

*/
/*
Read: 15:47 - 15:49
Solve: 15:50 - 16:23
Code: 16:24

Solution 1:

[i, j[
(i,j), i < j

i/j 0 1 2 3
0     0 0 0
1       0 0
2         0
3          


Brute force solution:
For each solution: O(n^2)
    Check solution O(n)
    
O(n^3)

Concatenation of 2 solutions, generating a third one:
    O(n^2)
16:01

Now I focused in the array, and tried to think recursively.


DP:

S(i, p)

p = {0,1}, includes or not the element i in the solution.

Final solution: max(S(n-1, 0), S(n-1, 1))

if p = 0:
    S(i, p) = max(S(i-1, 0), S(i-1, 1))
else:
    S(i, p) = max(nums[i], S(i-1, 1) + nums[i])


16:22

Complexity:
Time: O(n)
Space: O(n)




*/