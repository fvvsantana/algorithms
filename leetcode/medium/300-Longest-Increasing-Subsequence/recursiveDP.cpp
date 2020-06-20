class Solution {
public:
    int rows, cols;
    int lengthOfLIS(vector<int>& nums) {
        // 14:38
        rows = nums.size();
        cols = nums.size();

        // Create table
        vector<vector<int>> table(rows, vector<int>(cols, -1));

        // 14:47
        // Call the answer
        return lis(table, nums, 0, -1);
        // 14:55
    }

    int lis(vector<vector<int>>& table, vector<int>& nums, int i, int j){
        if(i == rows) return 0;

        // Check if it's calculated
        if(j != -1 && table.at(i).at(j) != -1){
            return table.at(i).at(j);
        }

        if(j == -1 || nums[i] > nums[j]){
            //        put i         don't put i
            return max(1 + lis(table, nums, i+1, i),
                       lis(table, nums, i+1, j));

        }else{
            //        don't put i
            return lis(table, nums, i+1, j);
        }
    }
};

/*
Reading: 5 minutes
Solving: 14:00 - 14:35
Coding recursive version: 14:38 -

Sorted:
2 3 5 7 9 10 18 101
2 4 3 5 1 0  7  6

Unsorted:
10,9,2,5,3,7,101,18
0  1 2 3 4 5 6   7


BF:
For each solution: O(2^n)
    Check solution O(n)

Time: O(n * 2^n)

// 14:02
L = [i, n[

i = position of the current element
j = position of the last element in the current sequence

DP:
First call: L(0, -1);

//L(n, j) = 0, for all j
if(i == n) return 0

if(j == -1 || nums[i] >= nums[j]){
                put i         don't put i
    L(i, j) = max(1 + L(i+1, i), L(i+1, j));

}else{
                don't put i
    L(i, j) = L(i+1, j);
}

L = [0, n-1] x [0, n-1]
        n       -1
// 14:34
Time: O(n^2)
Space: O(n^2)
//14:35
*/
