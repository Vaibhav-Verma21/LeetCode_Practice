/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2, res;
        inorder(root1, t1);
        inorder(root2, t2);
        
        int i = 0, j = 0;
        while (i < t1.size() && j < t2.size()) {
            if (t1[i] < t2[j]) res.push_back(t1[i++]);
            else res.push_back(t2[j++]);
        }
        
        while (i < t1.size()) res.push_back(t1[i++]);
        while (j < t2.size()) res.push_back(t2[j++]);
        
        return res;
    }
};