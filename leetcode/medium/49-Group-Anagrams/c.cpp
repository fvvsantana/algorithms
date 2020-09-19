class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 10:11
        vector<vector<string>> ans;
        vector<unordered_map<char, int>> signatures;
        
        for(string word : strs){
            
            // Create signature
            unordered_map<char, int> currentSig;
            for(char c : word){
                // Insert pair
                if(currentSig.find(c) == currentSig.end()){
                    currentSig.insert(pair<char,int>(c, 1));
                // Update pair
                }else{
                    currentSig.at(c)++;
                }
            }
            
            bool existingSignature = false;
            int i;

            for(i = 0; i < signatures.size(); i++){
                if(areEqual(signatures.at(i), currentSig)){
                    existingSignature = true;
                    break;
                }
            }
            
            if(existingSignature){
                ans.at(i).push_back(word);
            }else{
                signatures.push_back(currentSig);
                ans.push_back(vector<string>(1, word));
            }
            
        }
        
        
        return ans;
    }
    
    
    bool areEqual(unordered_map<char, int>& m1, unordered_map<char, int>& m2){
        if(m1.size() != m2.size()){
            return false;
        }
        
        for(pair<char, int> p : m1){
            if(m2.find(p.first) == m2.end() || p.second != m2.at(p.first)){
                return false;
            }
        }
        
        return true;
    }
};

/*
Read: 09:40 - 09:43
Solve: 09:43 - 10:04
Code: 10:11

Solution 1:
Sort the letters of the words.
Group the equal words together.

Solution 2:
Map<char, int> 
char: letter
int: how many times the letter appears in the word

Creating the map for the group = O(l)
isEqual(m, w) O(l)

m1, m2, m3

For each word: O(n)
    create the map here O(l)
    if the vector of unordered_maps contains the signature: O(n*l)
        group the word O(1)
    else:
        insert map O(1)
        

return a list of lists of strings, actually a vector of vectors of strings


unordered_map for signature

loop through all the maps: O(n)
        compare signatures: O(l)
        
Any of the maps are equal to the signature: O(n*l)
        



Complexity:
Time: O(n^2*l)
Space: O(n*l)
 
*/