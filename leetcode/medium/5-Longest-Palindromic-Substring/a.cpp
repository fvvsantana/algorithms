class Solution {
public:

    // Find the corresponding position of character from lps array to string
    inline int posOnString(int pos){
        return pos / 2;
    }

    // 10 min
    void expand(string s, vector<int> &lps, int i){
        int left = i - lps.at(i) - 1;
        int right = i + lps.at(i) + 1;
        bool inBound = left >= 0 && right < lps.size();
        bool isRightEven = right % 2 == 0;

        while(inBound &&
              (isRightEven || s.at(posOnString(left)) == s.at(posOnString(right)) )
             ){
            lps.at(i)++;
            left--;
            right++;

            inBound = left >= 0 && right < lps.size();
            isRightEven = right % 2 == 0;

        }
    }

    string longestPalindrome(string s) {

        if(s.length() == 0){
            return "";
        }

        vector<int> lps(2 * s.length() + 1);
        lps.at(0) = 0;
        lps.at(1) = 1;

        int c = 1;
        int r = 2;
        int i;
        int iMirror;
        int diff;

        // LPS information
        int maxLPSLength = 1;
        int maxLPSIndex = 1;

        for(i=2; max(r, i) < lps.size(); i++){

            iMirror = 2*c - i;
            diff = r - i;

            if(diff < 0){
                lps.at(i) = 0;
            }else{
                lps.at(i) = min(lps.at(iMirror), diff);
            }

            expand(s, lps, i);

            if(lps.at(i) > maxLPSLength){
                maxLPSLength = lps.at(i);
                maxLPSIndex = i;
            }

            if(r < i + lps.at(i)){
                c = i;
                r = i + lps.at(i);
            }

        }

        // Print substring from max LPS information
        int first = posOnString(maxLPSIndex - maxLPSLength);
        return string(s, first, maxLPSLength);
    }

};
