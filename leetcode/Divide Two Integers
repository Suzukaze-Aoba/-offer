class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend >=0) == (divisor >= 0);
        long long de = abs((long long)dividend);
        long long dr = abs((long long)divisor);
        long long res = exp(log(de) - log(dr));
        if (res > INT_MAX) {
            return sign ? INT_MAX : INT_MIN;
        }
        return sign ? (int)res : (int)-res;
    }
};
