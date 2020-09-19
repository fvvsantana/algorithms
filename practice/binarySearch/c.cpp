// 08:29

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Assume that vet is sorted.
    If vet contains elem, return the position of elem.
    Else, return -1.
*/
int binarySearchIterative(vector<int>& vet, int elem){
    /*
    []
    [3]
    [1,1,1]
    [1,1,1,1]
    [1,1]
    [1]


    */
    // 08:47
    // Define the interval [start, end[
    int start = 0;
    int end = vet.size();

    while(start != end){
        int middle = (start+end)/2;
        int middleElement = vet.at(middle);
        if(middleElement == elem){
            while(middle > 0 && middleElement == vet.at(middle - 1)){
                middle--;
            }
            return middle;
        }else if(elem < middleElement){
            end = middle;
        }else{
            start = middle + 1;
        }
    }

    return -1;
    // 08:56
}

int main(){
    vector<int> vet = {1,2,4,5};
    printf("%d\n", binarySearchIterative(vet, 3));

    int pos = lower_bound(vet.begin(), vet.end(), 3) - vet.begin();

    printf("%d\n", pos);
    

    return 0;
}