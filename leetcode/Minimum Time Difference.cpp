class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        bool *tp = new bool[24 * 60]();
        for (auto x : timePoints) {
            int pos = (x[0] - '0') * 10 + x[1] - '0';
            pos = pos * 60 + (x[3] - '0') * 10 + x[4] - '0';
            if (tp[pos]) {
                return 0;
            }
            tp[pos] = true;
        }
        int fst = -1;
        int pre = -1;
        int now = -1;
        int ans = 10000;
        for (int i = 0; i < 1440; ++i) {
            if (!tp[i]) {
                continue;
            }
            if (fst == -1) {
                fst = i;
                pre = i;
                continue;
            }
            if (now == -1) {
                now = i;
                (ans > now - pre) && (ans = now - pre);
            }
            else {
                pre = now;
                now = i;
                (ans > now - pre) && (ans = now - pre);
            }
        }
        return min(ans, fst + 1440 - now);
    }
};