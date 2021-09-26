class Solution {
public:
    bool isPalindrome(int x) {
        // check edges
        if(x < 0) return false;
        if(x == 0) return true;

        int nDigits = log10(x) + 1;
        int end = (nDigits-1)/2;
        int j;
        for(int i = 0; i <= end; i++){

            j = nDigits - i - 1;
            if(getDigit(x, i) != getDigit(x, j)){
                return false;
            }
        }
        return true;
    }

    int getDigit(int num, int index){
        return (num / ((int) pow(10, index))) % 10;
    }
};



/*
Read: 14:09 - 14:11
Solve: 14:12 - 14:20
Code: 14:20 - 14:58

Solution:
-10
0
1
3
first digit = x % 10
10 -> 1 0
11 ->

1 1 1

  V
2 1 0

    V
3 2 1 0

111 % 10 = 1


if negative return false
if

get the

Recursive:



*/
