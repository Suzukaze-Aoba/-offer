#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define M(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long LL;
const int maxn = 50000 + 5;
const LL mod = 1000000007;
char str[maxn];
bool operator_check(char op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}
int main() {

    scanf("%s",str);
    stack<char> s;
    for (int i = 0; str[i]; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
			while(str[i] && str[i] >= '0' && str[i] <= '9') {
			    putchar(str[i++]);
			}
			--i;
		    putchar(' ');
        }
        if (str[i] == '+' || str[i] == '-') {
			if (!s.empty()) {
				while(!s.empty() && operator_check(s.top())) {
					putchar(s.top());
					putchar(' ');
					s.pop();
				}
			}
			s.push(str[i]);
        }
        if (str[i] == '*' || str[i] == '/') {
			if (!s.empty()) {
				while(!s.empty() && (s.top() == '*' || s.top() == '/')) {
					putchar(s.top());
					putchar(' ');
					s.pop();
				}
			}
			s.push(str[i]);
        }
		if (str[i] == '(') {
			s.push(str[i]);
		}
		if (str[i] == ')') {
			while(!s.empty() && s.top() != '(') {
				putchar(s.top());
				putchar(' ');
				s.pop();
			}
			if (!s.empty()) {
				s.pop();
			}
		}
    }
    while(!s.empty()) {
        putchar(s.top());
		putchar(' ');
        s.pop();
    }
	puts("");
    return 0;
}
/**
(12/(33-2))*(10+4)+1/(3+9/2)
**/
