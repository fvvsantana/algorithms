class Solution {
public:
    enum State {EXPANDING, CONTRACTING, MOVING, END, ERROR};
    int minSubArrayLen(int s, vector<int>& nums) {
        // 15:48 write switch case block

        int i = 0;
        int j = 0;
        int sum = 0;
        int minValidLength;
        int currentWindowLength = 0;
        State state = EXPANDING;

        while(state != END && state != ERROR){
            // Expanding: find first solution that starts with i == 0
            switch(state){
                // 15:50 start writing expanding
                case EXPANDING:
                    if(sum < s){
                        if(j < nums.size()){
                            sum += nums.at(j);
                            j++;
                            currentWindowLength++;
                        }else{
                            state = ERROR;
                        }
                    }else{
                        state = CONTRACTING;
                        minValidLength = j - i;
                    }
                break;
                // 16:05 finish writing expanding

                // 16:05 start writing contracting
                case CONTRACTING:
                    if(sum >= s && currentWindowLength > 1){
                        minValidLength = j - i;
                        sum -= nums.at(i);
                        i++;
                        currentWindowLength--;
                    }else{
                        state = MOVING;
                    }
                break;
                // 16:26 finished CONTRACTING
                // let's have a break: 16:27 -> 16:36

                // This MOVING case is only acessible by CONTRACTING
                // The END state is only acessible by this MOVING case.
                // 16:37 start writing MOVING
                case MOVING:
                    // Possibilities:
                    // sum >= s     currentWindowLength > 1
                    // 0            0
                    // 0            1  stata = CONTRACTING
                    // 1            0  state = END


                    if(sum < s){

                        if(j < nums.size()){
                            sum = sum - nums.at(i) + nums.at(j);
                            i++;
                            j++;
                        }else{
                            state = END;
                        }
                    }else if(currentWindowLength == 1){
                        minValidLength = 1;
                        state = END;
                    }else{
                        state = CONTRACTING;
                    }

                break;
                // 17:09 finish writing MOVING
            }
        }

        if(state == ERROR){
            return 0;
        }
        return minValidLength;

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
Containment between 3 solutions (Union): 10:08
time: O(n^2)
space: O(n)

Previous + containment between 2 solutions: 10:17
time: O(n)
space: O(n)
24 minutes up to here

Start coding: 10:19

*/
