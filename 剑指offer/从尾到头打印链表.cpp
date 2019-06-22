/**
方法比较多，
考虑时间复杂度和空间复杂度最优的应该是链表反转，# 时间复杂度O(n),空间复杂度O(1)
A->B->C，每次把B指向C的指针断开前，记录下C的地址，防止断开后无法遍历后续节点
**/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>ans;
        if (head == NULL) {
            return ans;
        }
        if (head->next == NULL) {
            ans.push_back(head->val);
            return ans;
        }
        ListNode* now = head;
        ListNode* pre = head;
        while(head->next != NULL) {
            now = head->next;
            head->next = now->next;
            now->next = pre;
            pre = now;
        }
        while(now != NULL) {
            ans.push_back(now->val);
            now = now->next;
        }
        return ans;
    }
};
