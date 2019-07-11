class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        int k = (numRows - 1) << 1;
        int len = s.size();
        string ans = "";
        for (int i = 0, space = k; i < numRows; ++i) {
            int pos = i;
            while(pos < len) {
                ans = ans + s[pos];
                pos += space;
                space = k - space;
                space = space ? space : k;
            }
            space = k - (i + 1 << 1);
            space = space ? space : k;
        }
        return ans;
    }
};