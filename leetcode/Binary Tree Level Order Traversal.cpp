/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if (!root) {
            return ans;
        }
        
        int cnt = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> tmp;
            int num = 0;
            for (int i = 0; i < cnt; ++i) {
                TreeNode *node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                    ++num;
                }
                if (node->right) {
                    q.push(node->right);
                    ++num;
                }
            }
            ans.push_back(tmp);
            cnt = num;
        }
        return ans;
    }
};