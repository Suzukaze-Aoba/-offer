class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int dp[2005];
        int id = 0, mpos = 0;
        int len = s.length();
        string ss = "#";
        for (int i = 0; i < len; ++i) {
            ss = ss + s[i] + "#";
        }
        len = ss.length();
        dp[0] = 1;
        for (int i = 1; i < len; ++i) {
            if (i < mpos) {
                dp[i] = min(dp[(id << 1) - i], mpos - i);
            }
            else {
                dp[i] = 1;
            }
            while(i + dp[i] < len && i - dp[i] >= 0) {
                if (ss[i + dp[i]] == ss[i - dp[i]]) {
                    ++dp[i];
                    continue;
                }
                break;
            }
            if (dp[id] < dp[i]) {
                mpos = i + dp[i];
                id = i;
            }
        }
        string ans = "";
        for (int i = id - dp[id] + 2, j = 1; j < dp[id]; ++j, i += 2 ) {
            ans = ans + ss[i];
        }
        return ans;
    }
};