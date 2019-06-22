/**
F(n) = F(n - 1) + F(n - 2) , n >= 3
迭代法
**/
class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n <= 2) {
            return 1;
        }
        n -= 2;
        int a = 1, b = 1;
        int num = 0;
        for (int i = 1; i <= n; ++i) {
            num = a + b;
            a = b;
            b = num;
        }
        return num;
    }
};
