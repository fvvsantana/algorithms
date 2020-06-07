class Solution {
public:
    bool isValid(string str) {
        // 14:56
        stack<char> stk;
        char newChar;
        char top;
        // remind to check empty string
        for(int i = 0; i < str.length(); i++){
            newChar = str.at(i);
            if(stk.empty()){
                if(closingCharacter(newChar)){
                    return false;
                }else{
                    stk.push(newChar);
                }
            // Stack not empty
            }else{
                // 15:10
                // I know that the top is an openning character
                top = stk.top();
                if(closingCharacter(newChar)){
                    // Check if it's the right closing character
                    if(match(top, newChar)){
                        stk.pop();
                    }else{
                        return false;
                    }
                }else{
                    stk.push(newChar);
                }
                // 15:21
                // 15:26
            }
        }

        return stk.empty();
        // 15:28
    }

    inline bool closingCharacter(char c){
        return c == ')' || c == '}' || c == ']';
        // 15:05
    }

    inline bool match(char open, char close){
        switch(open){
            case '(':
                return close == ')';
            case '{':
                return close == '}';
            case '[':
                return close == ']';
            default:
                return false;
        }
    }
};

/*
Reading: 14:50 - 14:51
Solving: 14:51 -

Stack:
Time: O(n)
Space: O(n)
Finish this solution: 14:55


Total time for coding + thinking: 32 minutes
*/
