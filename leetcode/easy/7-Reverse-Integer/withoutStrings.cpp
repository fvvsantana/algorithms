class Solution {
public:
    int reverse(int x) {
        long int ans = 0;
        bool isNegative = x < 0;
        long int longX = abs((long int) x);

        // reverse the integer
        while(longX != 0){
            ans = 10 * ans + (longX % 10);
            longX = longX / 10;
        }

        // Check signal and then check overflow
        if(isNegative){
            if(-ans < numeric_limits<int>::min()){
                return 0;
            }else{
                return (int) -ans;
            }
        }else{
            if(ans > numeric_limits<int>::max()){
                return 0;
            }else{
                return (int) ans;
            }
        }

    }
};

/*
Solving: 14:43 -15:00

longest int = 2147483647;

x = 123

x = 12
ans = 3

x = 1
ans = 32

x = 0
ans = 321

long int ans;

check for overflow


*/
