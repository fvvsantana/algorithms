class Solution {
public:
    bool isValid(string s) {
        return wellFormedBrackets(s, 0, s.size());
        // finish code 14:49
    }

    // True if well formed, false else.
    // Change to reference and see if it works.
    // [start, end[
    bool wellFormedBrackets(string s, int start, int end, ){
        if(start == end){
            return true;
        }

        switch(s.at(start)){
            case '(':
                if(s.at(end-1) == ')' && wellFormedBrackets(s, start+1, end-1)){
                    return true;
                }
                return false;

            // finish this case: 14:45
            case '{':
                if(s.at(end-1) == '}' && wellFormedBrackets(s, start+1, end-1)){
                    return true;
                }
                return false;

            case '[':
                if(s.at(end-1) == ']' && wellFormedBrackets(s, start+1, end-1)){
                    return true;
                }
                return false;

            default:
                return false;
        }
        // finish this block 14:48
    }
};

/*
Reading: 14:20 - 14:22

Solving: 14:22 -

Let's use recursion.
Time: O(n)
Space:O(n)

String:
    ( well formed )
    { well formed }
    [ well formed ]
    ''


    well formed = well formed brackets

*/
