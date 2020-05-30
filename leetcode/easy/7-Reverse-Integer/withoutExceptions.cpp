#include <iostream>
#include <limits>

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

        // Convert string to long int
        long int aux = stol(sInverted);
        // Check for overflow
        if(aux > numeric_limits<int>::max() || aux < numeric_limits<int>::min()){
            return 0;
        }else{
            return x >= 0? aux : -aux;
        }
    }
};

int main(){
    //int longestInt = 2147483647;
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

longest int = 2147483647;



End: 17:19
*/
