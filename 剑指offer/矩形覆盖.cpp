/**
简单动态规划
当n=1时，矩形覆盖情况如下
a
a

当n=2时，矩形覆盖情况如下
a b   a a    
a b , b b

当n=3时，分情况讨论
(1)在n=2的情况下放置一块矩形得到，矩形覆盖情况如下
a b c   a a c
a b c , b b c

(2)在n=1的情况下放置两块矩形得到，矩形覆盖情况如下
a d e   a d d
a d e , a e e (前一种情况和n=2的一种方案重合，因此不加入方案数)

.
.
.

以此类推可得状态转移方程

状态转移方程：F(n) = F(n - 1) + F(n - 2)
**/
class Solution {
public:
    int rectCover(int number) {
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
