/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *ans = head;
        ListNode *pre = nullptr;
        ListNode *tail = nullptr;
        if (!head || m >= n) {
            return ans;
        }
        
        int cnt = 0;
        while(cnt + 1 < m) {
            pre = head;
            head = head->next;
            ++cnt;
        }
        
        tail = head;
        while(cnt + 1 < n) {
            tail = tail->next;
            ++cnt;
        }
        
        for (int i = 0; i < n - m; ++i) {
            ListNode *tmp = head->next;
            head->next = tail->next;
            tail->next = head;
            head = tmp;
        }
        
        if (!pre) {
            return tail;
        }
        else {
            pre->next = tail;
            return ans;
        }    
    }
};