class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //10:55
        // Create table
        int n = nums.size();
        int rows = n + 1;
        int cols = n + 1;
        vector<vector<int>> table(rows, vector<int> (cols));
        // Compute decreasing i
        // 11:12
        for(int i = n; i >= 0; i--){
            for(int j = 0; j <= n; j++){
                if(i == n){
                    table.at(i).at(j) = 0;
                }else if(j == n || nums.at(i) > nums.at(j)){
                    //                         pick i                   don't pick i
                    table.at(i).at(j) = max(1 + table.at(i+1).at(i), table.at(i+1).at(j));
                }else{
                    //                      can't pick i
                    table.at(i).at(j) = table.at(i+1).at(j);
                }
            }
        }
        return table.at(0).at(n);

    }


};

/*
Reading: 5 minutes
Solving: 14:00 - 14:35
Coding recursive version: 14:38 - 14:55
Coding iterative version: 10:55 - 11:31

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
First call: L(0, n);

//L(n, j) = 0, for all j
if(i == n) L(i, j) = 0

if(j == n || nums[i] > nums[j]){
                pick i         don't pick i
    L(i, j) = max(1 + L(i+1, i), L(i+1, j));

}else{
                don't pick i
    L(i, j) = L(i+1, j);
}

L = [0, n-1] x [0, n-1]
        n          -1
// 14:34
Time: O(n^2)
Space: O(n^2)
//14:35

i\j
    0 1 2 3
0
1
2
3

*/
