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
    bool res = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        dfs(root, 0, targetSum);
        return res;
    }
    
    void dfs(TreeNode* root, int curSum, int targetSum) {
        if (root == nullptr) {
            return;
        }
        
        curSum += root->val;
        if (root->left == nullptr && root->right == nullptr && curSum == targetSum) res = true;
        dfs(root->left, curSum, targetSum);
        dfs(root->right, curSum, targetSum);
    }
};