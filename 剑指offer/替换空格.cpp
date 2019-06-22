/**
每替换一个空格，字符串长度加2，所以新字符串的长度=原长度+空格数*2。
设置两个指针，一个指向原字符串末尾，一个指向新字符串末尾，依次往前替换新字符。
**/
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (!str || length <= 0) {
            return ;
        }
        int count = 0;
        int len = 0;;;
        for (int i = 0; str[i]; ++i) {
            ++len;
            (str[i] == ' ') && (++count);
        }
        int Len = len + (count << 1);
        int p1 = len;
        int p2 = Len;
        while(p1 >= 0 && p2 >= 0) {
            if (str[p1] == ' ') {
                str[p2--] = '0';
                str[p2--] = '2';
                str[p2--] = '%';
            }
            else {
                str[p2--] = str[p1];
            }
            --p1;
        }
        return ;
	}
};