/**
树状数组求逆序对
先对数组元素进行离散化，
离散化后得到每个元素在原数组中的排名(降序)，
把排名依次加入树状数组，每次加入前统计树状数组中有多少元素比元素大
**/
class Solution {
public:
    int InversePairs(vector<int> data) {
        int l = 0, r = data.size();
        if (r == 0) {
            return 0;
        }
        int *c = new int[r + 1];
        int *tmp = new int[r];
        for (int i = 0; i < r; ++i) {
            tmp[i] = data[i];
            c[i + 1] = 0;
        }
        sort(tmp, tmp + r);
        for (int i = 0; i < r; ++i) {
            data[i] = lower_bound(tmp, tmp + r, data[i]) - tmp + 1;
        }
        int mod = 1000000007;
        int ans = 0;
        for (int i = 0; i < r; ++i) {
            int res = 0;
            int x = data[i];
            while(x) {
                res = (res + c[x]) % mod;
                x -= x & (-x);
            }
            ans = (ans + i - res) % mod;
            x = data[i];
            while(x <= r) {
                ++c[x];
                c[x] %= mod;
                x += x & (-x);
            }
        }
        return ans % mod;
    }
};
