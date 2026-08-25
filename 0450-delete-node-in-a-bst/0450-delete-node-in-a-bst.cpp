class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (root->right == NULL)
                return root->left;
            if (root->left == NULL)
                return root->right;
            TreeNode* suc = root->right;
            while (suc->left != NULL) {
                suc = suc->left;
            }
            root->val = suc->val;
            root->right = deleteNode(root->right, suc->val);
        }
        return root;
    }
};
