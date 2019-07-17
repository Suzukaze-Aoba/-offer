/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL || k == 0) {
            return NULL;
        }
        ListNode* p1 = pListHead;
        ListNode* p2 = pListHead;
        for (int i = 1; i < k; ++i) {
            if (p2->next != NULL) {
                p2 = p2->next;
            }
            else {
                return NULL;
            }
        }
        for (;p2->next != NULL; ) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
