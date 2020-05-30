#include <iostream>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        // Convert integer to string
        string s = to_string(x);

        // Invert characters of string
        string sInverted = "";
        for(int i = s.length() - 1; i >= 0; i--){
            sInverted += s[i];
        }

        int ans;
        try{
            // Convert string to integer
            ans = stoi(sInverted);
        }catch(std::out_of_range& e){
            return 0;
        }

        return x >= 0? ans : -ans;
    }
};

int main(){
    // int longestInt = 2147483647;
    int longestInt = -123;
    //vector<int> entry = {0,1,2,3};
    int ans = Solution().reverse(longestInt);
    printf("%d\n", ans);
    return 0;
}



/*
Start: 16:52
        32
10000...9

80000...


End: 17:19
*/
