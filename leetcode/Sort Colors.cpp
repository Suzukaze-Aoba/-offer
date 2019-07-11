class Solution {
    void _swap(int &u, int &v) {
        if (u == v) {
            return ;
        }
        u ^= v;
        v ^= u;
        u ^= v;
        return ;
    }
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) {
            return ;
        }
        int n = nums.size();
        int l = 0, r = n - 1;
        for (int i = 0; i < n  && i <= r; ++i) {
            if (nums[i] == 0) {
                _swap(nums[i], nums[l]);
                ++l;
            }
            else if (nums[i] == 2) {
                _swap(nums[i], nums[r]);
                --i;
                --r;
            }
        }
        return ;
    }
};