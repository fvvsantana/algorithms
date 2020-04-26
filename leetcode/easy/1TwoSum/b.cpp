#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        unordered_map<int,int> ht(nums.size());
        int i = 0;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++, i++){

            // if it belongs to the set
            unordered_map<int,int>::iterator index = ht.find(target - (*it));
            if(index != ht.end()){
                ans[0] = index->second;
                ans[1] = i;
                break;
            }else{
                ht.insert(pair<int,int>(*it, i));
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
