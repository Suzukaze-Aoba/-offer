/**
用一个新栈保存原栈对应位置的最小值
新栈每个位置的值表示从栈底到该位置中的最小值
**/

class Solution {
    stack<int> s;
    stack<int> mins;
    int Min(const int &a, const int &b) {
        return a < b ? a : b;
    }
public:
    void push(int value) {
        s.push(value);
        if (mins.empty()) {
            mins.push(value);
        }
        else {
            mins.push(Min(value, mins.top()));
        }
        return ;
    }
    void pop() {
        s.pop();
        mins.pop();
        return ;
    }
    int top() {
        return s.top();
    }
    int min() {
        return mins.top();
    }
};
