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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) return result;

        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;

            nodes[hd][level].insert(node->val);

            if (node->left) {
                q.push(make_pair(node->left, make_pair(hd - 1, level + 1)));
            }
            if (node->right) {
                q.push(make_pair(node->right, make_pair(hd + 1, level + 1)));
            }
        }

        for (auto& [hd, level_map] : nodes) {
            vector<int> vertical;
            for (auto& [level, node_vals] : level_map) {
                vertical.insert(vertical.end(), node_vals.begin(), node_vals.end());
            }
            result.push_back(vertical);
        }

        return result;
    }
};
