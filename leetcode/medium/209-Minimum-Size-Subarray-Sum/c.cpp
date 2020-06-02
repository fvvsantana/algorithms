class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }

        int i = 0;
        int j = 0;
        int sum = 0;

        /*
        s = 5
        [1,2,3]
         i     j

        s = 7
        [1,2,3]
         i     j
         */

        // Find the minimal window starting at 0
        while(sum < s && j < nums.size()){
            // Calculate sum of expanded window
            sum += nums.at(j);

            // Expand window
            j++;

        }

        // This is the case where it's impossible to reach the s
        if(sum < s){
            return 0;
        }

        // 10:25
        int minWindowValidLength = j - i;
        int currentWindowLength = j - i;

        // Move the window and try to reduce it
        while(true){

            // Here I know that sum >= s
            // Contract window to the minimum - 1 (the size where sum < s happens)
            while(sum >= s && currentWindowLength > 0){
                sum -= nums.at(i);
                i++;
                currentWindowLength--;
            }
            minWindowValidLength = currentWindowLength + 1;

            if(currentWindowLength == 0 || j == nums.size()){
                break;
            }
            // 10: 40

            // Move the window by 1
            while(sum < s && j < nums.size()){
                sum = sum - nums.at(i) + nums.at(j);
                i++;
                j++;
            }

        }

        return minWindowValidLength;
    }
};

/*
Reading: 09:50 - 09:52
Solving O(n): 09:53 -


Define a "solution":
[i, j[

Space of search:

0 <= i < j <= n

  0 1 2 3 j
0 0 1 1 1
1 0 0 1 1
2 0 0 0 1
3 0 0 0 0
i

BF solution: 10:00
For each solution: O(n^2)
    Check if it's the solution. O(n)

time: O(n^3)
space: O(n)

union
intersection
complement
containment
ordering


Relationships between solutions:
Containment between 3 solutions: 10:08
time: O(n^2)
space: O(n)

Previous + containment between 2 solutions: 10:17
time: O(n)
space: O(n)
24 minutes up to here

Start coding: 10:19

*/
