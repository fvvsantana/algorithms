class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        //10:04
        int n = nums.size();
        vector<vector<int>> permutations(factorial(n), vector<int>(n));
        vector<int> currentPerm(n);
        int currentPermSize = 0;
        int nPermutations = 0;
        if(n == 0) return permutations;

        //unordered_set<int> rem(nums.begin(), nums.end());
        //move(nums.begin(), nums.end(), std::inserter(rem, rem.end()));

        unordered_set<int> rem(n);
        for(auto it = nums.begin(); it != nums.end(); it++){
            rem.insert(move(*it)); // if you want to move
            //rem.insert(*it); // if you want to copy
        }
        nums.clear();

        perm(rem, currentPerm, currentPermSize, permutations, nPermutations);

        return permutations;
    }


    //          TODO: maybe change to &rem
    void perm(unordered_set<int> &rem, vector<int> &currentPerm, int currentPermSize, vector<vector<int>>& permutations, int &nPermutations){
        /*
        for(auto it = rem.begin(); it != rem.end(); it++){
            cout << *it << endl;
        }
        cout << rem.size() << endl;
        */

        if(rem.size() == 1){
            // Append permutation
            currentPerm.at(currentPermSize) = *(rem.begin());
            currentPermSize++;
            for(int i = 0; i < currentPermSize; i++){
                permutations.at(nPermutations).at(i) = currentPerm.at(i);
            }
            nPermutations++;
        }else{
            for(auto it = rem.begin(); it != rem.end(); it++){
                currentPerm.at(currentPermSize) = *it;
                currentPermSize++;

                unordered_set<int> subset(rem);
                subset.erase(*it);

                perm(subset, currentPerm, currentPermSize, permutations, nPermutations);

                currentPermSize--;

            }
        }

    }

    // 10:02
    int factorial(int n){
        int ans = 1;
        for(int i = 2; i <= n; i++){
            ans *= i;
        }
        return ans;
        //10:03
    }
};

/*
Reading: 09:13 - 09:16
Solving: 09:17 - 09:24
Solving 2: 09:25 - 09:39
Table testing: 09:40 - 09:52
Complexity: 09:53 - 09:56
Coding: 10:00 to infinity, because idk how to use the things.

1 2 3
0 1 2

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

0 1 2
1 2
2

0
0 1
0 1 2
0 2 1

//09:25
list permutations[nums.size()!];

clist.allocate(nums.size());
perm(set with all the elements, empty list, empty list of permutations);
//
void perm(set, &clist, &permutations){

    if(|set| == 1 ){
        e = set.get()
        clist.append(e)
        permutations.copyAppend(clist)
        clist.pop()
    }else{
        for each element e in the set // O(n)
            clist.append(e)
            subset = set \ e            // this is a copy
            perm(subset, clist, permutations) //O(n)
            clist.pop()
    }


}

//09:39

// 09:40
Table testing:
1 2 3
[]

2 3
[1, ]


2
3
// 09:52
Complexity:
Time: O(n! * n^2 ) = O((n+2)!) = O(n!)
Space: O(n!)
// 09:56

*/
