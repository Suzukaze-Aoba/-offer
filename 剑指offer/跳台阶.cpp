/**
简单dp
情况1：由所有跳到第n-1级台阶的方案中跳一级跳到第n级台阶
情况2：由所有跳到第n-2级台阶的方案中跳两级级跳到第n级台阶
转移方程：dp[n] = dp[n - 1] + dp[n - 2] , n > 2 且 dp[1] = 1 , dp[2] = 2
本质就是斐波那契数列，使用迭代法求得
**/
class Solution {
public:
    int jumpFloor(int number) {
        int& n = number;
        if (n == 0) {
            return 0;
        }
        if (n <= 3) {
            return n;
        }
        int a = 2, b = 3;
        int ans = 0;
        n -= 3;
        for (int i = 1; i <= n; ++i) {
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};
/**
1 1 1 1
1 1 2
1 2 1
2 1 1
2 2
**/
