/**
用双端队列deque模拟滑动窗口
队列中记录的是数值的下标
遍历到数组的第i个元素时：
（1）把超出窗口范围的队首元素弹出
（2）如果队尾元素比第i个元素小，弹出，因为这个元素不可能在之后作为滑动窗口的最大值

使用循环队列模拟deque
时间复杂度O(n) 空间复杂度O(k) , n为数组长度 ，k为滑动窗口长度
**/

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ans;
        int len = num.size();
        if (size < 0 || size > len) {
            return ans;
        }
        if (size == 1) {
            return num;
        }
        if (size == len) {
            int mx = -(1 << 30);
            for (auto x : num) {
                if (mx < x) {
                    mx = x;
                }
            }
            ans.push_back(mx);
            return ans;
        }
        int *que = new int[size];
        int head = 0, tail = 0, cnt = 0;
        for (int i = 0; i < len; ++i) {
            while(cnt) {
                if (i - que[head] >= size) {
                    ++head;
                    if (head == size) {
                        head = 0;
                    }
                    --cnt;
                }
                else {
                    break;
                }
            }
            while(cnt) {
                int pos = (tail - 1 + size) % size;
                if (num[i] > num[que[pos]]) {
                    tail = tail - 1;
                    tail = (tail + size) % size;
                    --cnt;
                }
                else {
                    break;
                }
            }
            que[tail++] = i;
            if (tail == size) {
                tail = 0;
            }
            ++cnt;
            if (i >= size - 1) {
                ans.push_back(num[que[head]]);
            }
        }
        return ans;
    }
};
