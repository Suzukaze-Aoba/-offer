/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void _swap(int &u, int &v) {
        u ^= v;
        v ^= u;
        u ^= v;
        return ;
    }
    void heapify(int *heap, int *id, int &hpsiz, int k) {
        if (hpsiz <= 1) {
            return ;
        }
        while(1) {
            bool flag = false;
            int tmp = k;
            int chd = k << 1;
            if (chd <= hpsiz) {
                if (heap[chd] < heap[tmp]) {
                    tmp = chd;
                    flag = true;
                }
            }

            chd = k << 1 | 1;
            if (chd <= hpsiz) {
                if (heap[chd] < heap[tmp]) {
                    tmp = chd;
                    flag = true;
                }
            }
            if (flag) {
                _swap(heap[k], heap[tmp]);
                _swap(id[k], id[tmp]);
                k = tmp;
            }
            else {
                break;
            }
        }
        return ;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        ListNode *head = new ListNode(-1);
        ListNode *ans = head;
        int k = lists.size();
        int *heap = new int[k + 1]();
        int *id = new int[k + 1]();
        int hpsiz = 0;
        int emptylist = 0;
        for (int i = 0; i < k; ++i) {
            if (!lists[i]) {
                ++emptylist;
                continue;
            }
            heap[++hpsiz] = lists[i]->val;
            id[hpsiz] = i;
        }
        if (!hpsiz) {
            return nullptr;
        }
        for (int i = hpsiz >> 1; i >= 1; --i) {
            heapify(heap, id, hpsiz, i);
        }
        while(1) {
            head->next = lists[id[1]];
            head = head->next;
            lists[id[1]] = lists[id[1]]->next;
            if (!lists[id[1]]) {
                ++emptylist;
                _swap(heap[1], heap[hpsiz]);
                _swap(id[1], id[hpsiz]);
                --hpsiz;
                heapify(heap, id, hpsiz, 1);
            }
            else {
                heap[1] = lists[id[1]]->val;
                heapify(heap, id, hpsiz, 1);
            }
            if (emptylist == k) {
                break;
            }
        }
        while(hpsiz) {
            head->next = lists[id[1]];
            head = head->next;
            _swap(heap[1], heap[hpsiz]);
            _swap(id[1], id[hpsiz]);
            --hpsiz;
            heapify(heap, id, hpsiz, 1);
        }
        return ans->next;
    }
};
