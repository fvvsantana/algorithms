class Solution {
public:
    struct Node{
        char c;
        Node* next;
        Node(char cc = '\O', Node* cNext = nullptr) : c(cc), next(cNext){}
    };

    string convert(string s, int numRows) {

        if(numRows <= 1){
            return s;
        }

        // allocate array of nodes
        Node* heads[numRows];
        Node* tails[numRows];
        for(int i = 0; i < numRows; i++){
            heads[i] = nullptr;
            tails[i] = nullptr;
        }

        // loop over string generating linked lists
        // Insert nodes in the end of linked lists
        int pos = 0;
        bool downwards = true;
        for(int i = 0; i < s.length(); i++){
            // Create a node
            Node* newNode = new Node(s.at(i), nullptr);

            // Insert node on the tail
            if(heads[pos] == nullptr){
                heads[pos] = newNode;
                tails[pos] = newNode;
            }else{
                tails[pos]->next = newNode;
                tails[pos] = newNode;
            }

            // Update pos
            if(downwards){
                if(pos < numRows - 1){
                    pos++;
                }else{
                    downwards = false;
                    pos--;
                }
            }else{
                if(pos > 0){
                    pos--;
                }else{
                    downwards = true;
                    pos++;
                }
            }

        }

        // loop over linked lists accumulating the characters
        string ans = "";
        Node* currentNode = nullptr;
        for(int i = 0; i < numRows; i++){
            currentNode = heads[i];

            // loop over linked list
            while(currentNode){
                ans += currentNode->c;
                currentNode = currentNode->next;
            }
        }

        return ans;
    }
};

/*
Start: 15:30
||-> last node of linked list
||
||

||-> p->a
||-> a->p
||-> y

Time: O(n)
Space: O(n)


End: 16:15
*/
