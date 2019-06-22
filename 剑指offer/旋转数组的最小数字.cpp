/**
简单二分
旋转后前一段序列肯定比后一段要大
如果mid比左边的元素大，移动左区间，否则移动右区间
**/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size() == 0) {
            return 0;
        }
        vector<int>& arr = rotateArray;
        int l = 0, r = arr.size() - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if (arr[mid] == arr[l]) {
                return arr[mid + 1];
            }
            if (arr[mid] > arr[l]) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return 0;
    }
};
