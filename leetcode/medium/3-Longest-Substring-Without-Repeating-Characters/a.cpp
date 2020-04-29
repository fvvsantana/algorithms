#include <unordered_set>
class Solution {
public:
    void foo(string &s, int length, int &bestLength, int p){
        unordered_set<char> set;
        int n = 0;
        for(int i = p; i < length; i++){
            if(set.find(s[i]) == set.end()){
                set.insert(s[i]);
                n++;
                if(bestLength < n){
                    bestLength = n;
                }
            }else{
                return;
            }
        }
    }

    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        if(length < 2) return length;

        int bestLength = 1;
        for(int p = 0; p < length - 1; p++){

            if(length - p > bestLength){
                foo(s, length, bestLength, p);
            }
        }
        return bestLength;

    }


};
