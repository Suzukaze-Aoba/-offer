/**
已知二维数组由上到下，由左到右递增,
从左下角开始搜索，
如果target比当前整数小，则往上找
如果target比当前整数大，则往右找
**/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        int i = row - 1 , j = 0;
        while(i >= 0 && j < col) {
            if(target < array[i][j]) {
                --i;
            }
            else if(target > array[i][j]) {
                ++j;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
