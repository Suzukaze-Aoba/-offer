//**
同跳台阶问题
转移方程：F(n) = F(n - 1) + F(n - 2) + ... + F(2) + F(1) + 1
把n-1带入F(n)可得F(n - 1) = F(n - 2) + F(n - 3) + ... + F(2) + F(1) + 1

F(n) = [ F(n - 2) + F(n - 3) + ... + F(2) + F(1) + 1 ] + [ F(n - 2) + F(n - 3) + ... + F(2) + F(1) + 1 ]
     = F(n - 1) * 2
     = 2^(n - 1) , n > 0
**/

class Solution {
public:
    int jumpFloorII(int number) {
        if (number <= 2) {
            return number;
        }
        return 1ll << (number - 1);
    }
};
/**
0 1 2 4 8 
**/
