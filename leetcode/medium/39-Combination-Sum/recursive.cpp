class Solution {

struct Node{
    // index of number in candidates
    int index;
    // amount of times the number is considered in the sum
    int amount;

    Node(int i, int a){
        index = i;
        amount = a;
    }
};
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());

        list<Node> addends;
        comb(candidates, target, ans, addends, 0);

        return ans;

    }

    // Append to addends and then to ans all the combinations of indices of candidates where the sum adds to target. The indices in addends should be increasing (not strictly).
    void comb(vector<int> &candidates, int &target, vector<vector<int>> &ans, list<Node> &addends, int sum){
        /*
        for(auto it = addends.begin(); it != addends.end(); it++){
            cout << '(' << it->index << ',' << it->amount << "),";
        }
        cout << endl;
        */
        int n = candidates.size();
        if(sum == target){
            // Append curent addends to ans
            vector<int> currentComb;
            for(auto it = addends.begin(); it != addends.end(); it++){
                for(int i = 0; i < it->amount; i++){
                    currentComb.push_back(candidates.at(it->index));
                }
            }
            ans.push_back(move(currentComb));

        // To do: remove this condition
        }else if(sum < target){
            bool firstCall = false;
            if(addends.empty()){
                firstCall = true;
            }

            if(firstCall){
                for(int i = 0; i < n && sum + candidates.at(i) <= target; i++){

                    addends.push_back(move(Node(i, 1)));
                    sum += candidates.at(i);
                    comb(candidates, target, ans, addends, sum);
                    addends.pop_back();
                    sum -= candidates.at(i);
                }
            }else{
                Node& last = addends.back();
                for(int i = last.index; i < n && sum + candidates.at(i) <= target; i++){
                    if(i == last.index){
                        // Update addends
                        last.amount++;
                    }else{
                        addends.push_back(move(Node(i, 1)));
                    }

                    sum += candidates.at(i);
                    comb(candidates, target, ans, addends, sum);

                    if(i == last.index){
                        // Update addends
                        last.amount--;
                    }else{
                        addends.pop_back();
                    }
                    sum -= candidates.at(i);
                }
            }



        }
    }



};

/*
Try to think recursively
Reading: 16:49, 3 min
Solving: 16:52, 22 min
Coding: 17:14, 16 min, but not finished
End: 17:30

[i], i are n amounts, that is, i integer in [0, target/i]
[j], j in candidates.

Brute force:
m = target/(min.candidates)
target/i = O(target/(min.candidates))
For each solution O(m^n)
    Check solution O(n)

Complexity:
Time: O(n * m^n)
Space: O(n)

// 16:59

Recursive solution:
Sort the array

2 2 2 2
2 2 3
2 3 6
2 6

0 0 0 0
0 0 1
0 1 2


candidates.sort();
ans = [];

addendsPos = []

comb(&candidates, target, &ans, &addendsPos){
    if(target > 0, < 0, == 0)
    for each i position in candidates:
        addendsPos.append(candidates[i]);
        comb(candidates, target - candidates[i], ans, addendsPos)
}
// 17:12




*/
