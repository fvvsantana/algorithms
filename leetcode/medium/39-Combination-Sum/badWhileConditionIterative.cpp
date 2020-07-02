class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        // 07:55
        list<int> addends;
        vector<vector<int>> ans;
        bool running = true;
        int sum = 0;

        if(n == 0){
            running = false;
        }


        while(running){
            for(auto it = addends.begin(); it != addends.end(); it++){
                cout << *it << ",";
            }
            cout << endl;
            if(sum < target){
                //
                int last = addends.back();
                addends.push_back(last);
                sum += candidates.at(last);
            }else if(sum == target){
                // copy addends
                vector<int> currentAddends;
                for(auto it = addends.begin(); it != addends.end(); it++){
                    currentAddends.push_back(candidates.at(*it));
                }
                ans.push_back(move(currentAddends));

                sum -= candidates.at(addends.back());
                addends.pop_back();

                int last = addends.back();
                while(last == n-1 && addends.size() > 0){
                    int last = addends.back();
                    sum -= candidates.at(last);
                    addends.pop_back();
                }

                if(addends.size() == 0){
                    running = false;
                    continue;
                }

                last = addends.back();
                sum -= candidates.at(last);
                addends.pop_back();

                last++;
                if(last == n){
                    if(addends.size() == 0){
                        running = false;
                    }
                    continue;
                }else{
                    addends.push_back(last);
                    sum += candidates.at(last);
                }

                /*
                [8]
                */
            }else{
                int last = addends.back();
                sum -= candidates.at(last);
                addends.pop_back();

                last = addends.back();
                while(last == n-1 && addends.size() > 0){
                    int last = addends.back();
                    sum -= candidates.at(last);
                    addends.pop_back();
                }

                if(addends.size() == 0){
                    running = false;
                    continue;
                }

                last = addends.back();
                sum -= candidates.at(last);
                addends.pop_back();

                last++;
                if(last == n){
                    if(addends.size() == 0){
                        running = false;
                    }
                    continue;
                }else{
                    addends.push_back(last);
                    sum += candidates.at(last);
                }
            }
        }

        return ans;
    }
};

/*
Reading: 07:34, 4 min
Solving: 07:38, 17 min
Coding: 07:55,
Pseudo code:
Complexity: 08:10,
End: 08:20,


Solution:
[i], i in [0, n-1]

Sort

[2,3,6,7] 7
2
5
2 2 2 2 w
2 2 2
2 2 3 good
2 3 3 w
2 6 w
3 3 3 w
3 6 w
6 6 w
7

2


array of predecessors:
[0 0 0 0] wrong
[0 0 1] good
[0 1 1] wrong
[0 2] w
[1 1 1] w
[1 2] w
[2 2] w
[3] g

[]

Arrange n target/minCand = n!/ (n-target/minCand)!
Complexity:
Time: O( n!/ (n-target/minCand)!)
Space: O(min(target/minCand, n))


*/
