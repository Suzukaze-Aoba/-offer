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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        stack<TreeNode*> stk;
        TreeNode *node = root;
        while(!stk.empty() || node) {
            
            while(node) {
                ans.push_back(node->val);
                stk.push(node);
                node = node->right;
            }
            
            if (!stk.empty()) {
                node = stk.top();
                stk.pop();
                node = node->left;
            }
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};