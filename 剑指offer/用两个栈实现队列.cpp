/**
前一个栈模拟队尾，执行入队操作，
后一个栈模拟队首，执行出队操作，
每当调用pop()时，把队尾(前一个栈)的元素全部移到队首(后一个栈),
此时后一个栈的栈顶元素就是队首元素
**/
class Solution
{
public:
    void push(int node) {
        s1.push(node);
        return ;
    }
    int pop() {
        if (s2.size()) {
            int num = s2.top();
            s2.pop();
            return num;
        }
        else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            int num = s2.top();
            s2.pop();
            return num;
        }
    }

private:
    stack<int> s1;
    stack<int> s2;
};
