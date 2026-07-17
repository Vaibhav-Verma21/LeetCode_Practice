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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levelSums;
      
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
      
        while (!bfsQueue.empty()) {
            long long currentLevelSum = 0;
            int currentLevelSize = bfsQueue.size();
          
            for (int i = 0; i < currentLevelSize; ++i) {
                TreeNode* currentNode = bfsQueue.front();
                bfsQueue.pop();
              
                currentLevelSum += currentNode->val;
              
                if (currentNode->left) {
                    bfsQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    bfsQueue.push(currentNode->right);
                }
            }
          
            levelSums.push_back(currentLevelSum);
        }
      
        if (levelSums.size() < k) {
            return -1;
        }
        sort(levelSums.rbegin(), levelSums.rend());
      
        return levelSums[k - 1];
    }
};