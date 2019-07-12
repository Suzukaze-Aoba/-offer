class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        int *last = new int[256];
        memset(last, -1, sizeof(int));
        int head = 0;
        int len = s.size();
        int anslen = 0;
        for (int i = 0; i < len; ++i) {
            if (head <= last[s[i]]) {
                anslen = max(anslen, i - head);
                head = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        return max(anslen, len - head);
    }
};