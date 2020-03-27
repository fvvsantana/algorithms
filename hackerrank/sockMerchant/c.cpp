#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

vector<string> split_string(string);
typedef unsigned char sint;

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    unordered_set<sint> ht(100);
    sint pairs = 0;

    for(sint i = 0; i < n; i++){
        if(ht.find(ar[i]) != ht.end()){
            pairs++;
            ht.erase(ar[i]);
        }else{
            ht.insert(ar[i]);
        }
    }
    return pairs;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i=0; i < n; i++){
        cin >> ar[i];
    }
    int out = sockMerchant(n, ar);
    cout << out;
    return 0;
}
