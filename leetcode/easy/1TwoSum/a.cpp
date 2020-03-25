#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans = {0,1};
        for(int i=0; i < nums.size(); i++){
            printf("%d\n", nums[i]);
        }

        return nums;
    }
};

int main(){
    Solution sol;
    vector<int> ans;
    vector<int> entry = {0,1,2};
    ans = sol.twoSum(entry, 3);
    printf("%d %d\n", ans[0], ans[1]);
    return 0;
}
