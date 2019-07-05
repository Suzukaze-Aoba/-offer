/**
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
考虑到最优的时间复杂度应该使用快速加计算
int quickadd(int n) { // 快速加求1+2+..+n
    int res = 0;
    int a = n + 1;
    while(n) { // 对应(n) && (...)
        if (n & 1) {
            res += a; // 对应(n & 1) && (res += a)
        }
        a <<= 1; n >>= 1; //对应dfs(a << 1, n >> 1)
    }
    return res >> 1; // 对应dfs(n + 1, n) >> 1
}
**/

class Solution {
    int dfs(int a, int n) {
        int res = 0;
        (n) && (res = res + dfs(a << 1, n >> 1));
        (n & 1) && (res += a);
        return res;
    }
public:
    int Sum_Solution(int n) {
        return dfs(n + 1, n) >> 1;
    }
};
