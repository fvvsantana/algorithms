#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        unordered_map<int, int> ht(nums.size());

        // Generate hash table <value, index>
        for(int i=0; i < nums.size(); i++){
            ht.insert(pair<int, int>(nums[i], i));
        }

        for(int i=0; i < nums.size(); i++){
            unordered_map<int,int>::iterator index = ht.find(target - nums[i]);
            if(index != ht.end() && index->second != i){
                ans[0] = i;
                ans[1] = index->second;
                break;
            }
        }

        return ans;
    }
};

int main(){
    //vector<int> entry = {0,1,2,3};
    vector<int> entry = {3,2,4};
    vector<int> ans = Solution().twoSum(entry, 6);
    printf("%d %d\n", ans[0], ans[1]);
    return 0;
}
