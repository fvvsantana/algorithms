class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // 15:01
        int n = nums.size();

        // Allocate structure for permutations
        vector<vector<int>> permutations(factorial(n), vector<int>(n, 0));

        int nPerms = 0;
        // 15:10
        // Fill the structure
        if(n > 0){
            perm(nums, 0, permutations, nPerms);
        }

        // Return structure
        return permutations;
        // 15:18
    }
    /*

    [1]
    []
    */

    // 15:12
    void perm(vector<int>& nums, int start, vector<vector<int>>& permutations, int &nPerms){
        int n = nums.size();

        if(start == n - 1){
            for(int i = 0; i < n; i++){
                permutations.at(nPerms).at(i) = nums.at(i);
            }
            nPerms++;
        }else{
            // 15:15
            for(int i = start; i < n; i++){
                swap(nums.at(start), nums.at(i));
                perm(nums, start+1, permutations, nPerms);
                swap(nums.at(start), nums.at(i));
            }
        }
    }


    // 15:06
    int factorial(int n){
        int ans = 1;
        for(int i = 2; i <= n; i++){
            ans *= i;
        }
        return ans;
    }



};

/*
Reading: 14:21 - 14:22
Solving: 14:22 - 14:44
Pseudo coding: 14:46 - 15:00
Coding: 15:00 - 15:18

Sol 2: No way, I still need to use the sets. NVM
Sol 3: Solution with swaps:
1 2 3

1 2 3
1 3 2

2 1 3
2 3 1

3 2 1
3 1 2

// 14:47

perm(nums, 0, permutations, 0);


void perm(vector &nums, int start, permutations, int &nPerms){
    int n = nums.size();
    if(start == n - 1){
        permutations[nPerms] = nums;
        nPerms++;
    }else{
        for(int i = start; i < n; i++){
            swap(nums.at(i), nums.at(start));
            perm(nums, start+1, permutations);
            swap(nums.at(i), nums.at(start));
        }
    }
}

// 14:58
Complexity:
Time: O(n * n!) = O(n!)
Space: O(n) without answer
        O(n!) with answer

// 15:00



*/
