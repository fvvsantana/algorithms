class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> currentCombinations;
        vector<vector<int>> ans;

        // 09:39
        // For each length of combination
        for(int i = 0; i < n; i++){
            // Generate combinations
            //currentCombinations =  combinations(nums, i);

            // Move combinations to ans
        }
        return ans;
    }

    // 09:43
    // Return list of combinations
    vector<vector<int>> combinations(vector<int>& nums, int i){
        int n = nums.size();
        // 09:50

        // C n i = n! / ((n-i)! * i!)
        // Create structure
        vector<vector<int>> ans(factorial(n) / (factorial(n-i) * factorial(i)));

        // Create combinations recursively
        // 10:05 (because I thought wrong about how to make combinations)

    }

    void rCombinations(vector<vector<int>>& ans)

    // 09:48
    int factorial(int n){
        int ans = 1;
        for(int i = 2; i <= n; i++){
            ans *= i;
        }
        return ans;
    }
};

/*
Reading: 09:17 - 09:19
Solving: 09:19 - 09:37
Coding: 09:37 -

//09:20
Solution 1: Combinations
C n i
i belongs to [0, n]
//09:22

//09:23
Solution 2: Try to think recursively
1 2 3

[]
[1]

[]
[2]
[3]
[2,3]

[1] U power([2,3])
// 09:29

// 09:29
// Choose solution 1
// 09:33

Complexity:
Time: O(n * 2^n)
Space: O(n * 2^n)
// 09:36


*/
