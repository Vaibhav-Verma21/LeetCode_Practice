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
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);
        return buildBalancedBST(0, sortedValues.size() - 1);
    }

private:
    vector<int> sortedValues;

    void inorderTraversal(TreeNode* node) {
        if (!node) {
            return;
        }
        inorderTraversal(node->left);
        sortedValues.push_back(node->val);
        inorderTraversal(node->right);
    }

    TreeNode* buildBalancedBST(int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        TreeNode* leftSubtree = buildBalancedBST(left, mid - 1);
        TreeNode* rightSubtree = buildBalancedBST(mid + 1, right);
        return new TreeNode(sortedValues[mid], leftSubtree, rightSubtree);
    }
};
