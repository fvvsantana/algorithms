class Solution {
public:
    bool isValid(string s) {
        int end;
        return wellFormedBrackets(s, 0, end, '$');

        // finish code 14:49
        // it doesn't work for this case: "()[]{}"
        // I'll try to adjust it now: 15:07

        // "(){"
        // "{"
    }

    /*
    well formed():

    ( well formed ) well formed
    { well formed } well formed
    [ well formed ] well formed
    ''
    */

    // True if well formed, false else.
    // Change to reference and see if it works.
    // [start, end[
    // The '$' tells me that I'm not expecting closing braces.
    bool wellFormedBrackets(string &s, int start, int& end, char close){
        // empty string
        if(start == s.size()){
            if(close == '$'){
                return true;
            }
            return false;
        }

        if(s.at(start) == close){
            end = start + 1;
            return true;
        }

        switch(s.at(start)){
            case '(':
                if(wellFormedBrackets(s, start+1, end, ')')){
                    if(close == '$'){
                        return wellFormedBrackets(s, end, end, '$');
                    }else{
                        if(s.at(end) == close){
                            return wellFormedBrackets(s, end, end, '$');
                        }
                        return false;
                    }
                }
                return false;

            // finish this case: 14:45
            case '{':
                if(wellFormedBrackets(s, start+1, end, '}')){
                    if(close == '$'){
                        return wellFormedBrackets(s, end, end, '$');
                    }else{
                        if(s.at(end) == close){
                            return wellFormedBrackets(s, end, end, '$');
                        }
                        return false;
                    }
                }
                return false;

            case '[':
                if(wellFormedBrackets(s, start+1, end, ']')){
                    if(close == '$'){
                        return wellFormedBrackets(s, end, end, '$');
                    }else{
                        if(s.at(end) == close){
                            return wellFormedBrackets(s, end, end, '$');
                        }
                        return false;
                    }
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
Space: O(n)

String:

    well formed():

    ( well formed ) well formed
    { well formed } well formed
    [ well formed ] well formed
    ''


*/
