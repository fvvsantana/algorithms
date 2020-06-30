class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //08:28
        // Create answer
        vector<vector<int>> ans;

        list<int> cList;
        // Calculate and allocate answer
        power(nums, cList, 0, ans);

        // Return answer
        return ans;
    }
    // 08:35
    void power(vector<int>& nums, list<int>& cList, int i, vector<vector<int>>& ans){
        if(i == nums.size()){
            vector<int> aux(cList.size());
            int j = 0;
            for(auto it = cList.begin(); it != cList.end(); it++, j++){
                aux.at(j) = *it;
            }
            ans.push_back(move(aux));
        }else{
            power(nums, cList, i+1, ans);
            cList.push_back(nums.at(i));
            power(nums, cList, i+1, ans);
            cList.pop_back();
        }
    }
    // 08:41

    /*
    // Append all sets to the list, that belongs to the powerset using the elements in [i, n-1]
    power(&nums, &clist, int i, &ans){
        if(i == n){
            // Allocating and appending
            ans.append( copy(clist));
        // 08:21
        }else{
            power(nums, clist, i+1, ans);
            clist.append(nums.at(i));
            power(nums, clist, i+1, ans);
            clist.pop()
        }
    }
    */
};
/*
Reading: 08:05 - 08:07
Solving: 08:07 - 08:19
Pseudo coding: 08:19 - 08:28
Coding: 08:28 - 08:41
Make code work: 08:41 - 08:47

Solution: Truth table

2^n

1 2 3

power([1]) U power([2, 3])

[1]
[]

linked list
1

0 0 0
0 0 1
0 1 0
0 1 1 ...

1
1 2
2 3

power(nums, [], 0, [])

// 08:19
// Append all sets to the list, that belongs to the powerset using the elements in [i, n-1]
power(&nums, &clist, int i, &subsets){
    if(i == n){
        // Allocating and appending
        subsets.append( copy(clist));
    // 08:21
    }else{
        power(nums, clist, i+1, subsets);
        clist.append(nums.at(i));
        power(nums, clist, i+1, subsets);
        clist.pop()
    }
}
// 08:25
Complexity:
Time: O(n * 2^n)
Space: O(n * 2^n) with ans
        O(n) without ans
// 08:28


*/
