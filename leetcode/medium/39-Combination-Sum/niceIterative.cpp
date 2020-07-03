class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        list<int> adds;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        if(n == 0){
            return ans;
        }
        adds.push_back(0);
        sum += candidates.at(0);
        bool carry = false;

        while(!adds.empty()){
            for(auto it = adds.begin(); it != adds.end(); it++){
                cout << *it << ",";
            }
            cout << endl;
            // assuming not empty list
            // sum updated
            // list updated
            // carry updated
            if(carry){
                int last = adds.back();
                if(last == n-1){
                    adds.pop_back();
                    sum -= candidates.at(last);
                }else{
                    sum = sum - candidates.at(last) + candidates.at(++last);
                    adds.back() = last;
                    carry = false;
                }
            // carry is used
            }else if(sum < target){
                //09:10
                // copy last element
                int last = adds.back();
                adds.push_back(last);

                // update the sum
                sum += candidates.at(last);
            }else if(sum == target){
                vector<int> sol;
                for(auto it = adds.begin(); it != adds.end(); it++){
                    sol.push_back(candidates.at(*it));
                }
                // add solution to ans
                ans.push_back(move(sol));

                // Update list
                int last = adds.back();
                adds.pop_back();

                // Update sum
                sum -= candidates.at(last);

                // Updated carry
                carry = true;

            }else{
                // Update list
                int last = adds.back();
                adds.pop_back();

                // Update sum
                sum -= candidates.at(last);

                // Updated carry
                carry = true;
            }
        }

        return ans;
    }
};

/*
Reading: 08:36, 4 min
Solving: 08:40, 21 min
Coding: 09:03, 47 min
End coding: 09:50
Testing:

Solution 1:
[i], i in [0, inf[, n indices i
[j], j in candidates, from 0 to inf numbers j


i = O(target/(min.candidates))
m = target/(min.candidates)

Brute force:
For each solution O(m^n)
    Check solution O(n)

Complexity:
Time: O(n * m^n)
Space: O(n)
// 08:48

Sort
[2 3 6 7]
7

0 0 3 3 3 3
2 2 7 7 7 7 = target g
2 2 7 7
2 3

list<index, amount>

[0 0 0] adds
2 2 2
2 2 2 2 w
2 2 3 g
2 3 3 w
2 6 w
3 3 3 w
3 6 w
6 6 w
7 g

while(!list.empty())
Complexity:
m = target/(min.candidates)
Time: O(m * n^m), average(n^m)
Space: O(max(m, n))


*/
