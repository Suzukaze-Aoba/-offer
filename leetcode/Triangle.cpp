class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        vector<vector<int> > &nums = triangle;
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0][0];
        }
        int len = nums.size();
        vector<int> dp = nums[len - 1];
        for (int i = len - 2; i >= 0; --i) {
            int siz = nums[i].size();
            for (int j = 0; j < siz; ++j) {
                dp[j] = nums[i][j] + min(dp[j] , dp[j + 1]);
            }
        }
        return dp[0];
    }
};