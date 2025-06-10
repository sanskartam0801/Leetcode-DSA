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
    unordered_map<TreeNode*, int> dp; // use a map instead of an array

    int solve(TreeNode* root){
        if (root == NULL) return 0;
        if (dp.count(root)) return dp[root];

        int notake = solve(root->left) + solve(root->right);

        int take = root->val;
        if (root->left)
            take += solve(root->left->left) + solve(root->left->right);
        if (root->right)
            take += solve(root->right->left) + solve(root->right->right);

        return dp[root] = max(take, notake);
    }

    int rob(TreeNode* root) {
        return solve(root);
    }
};
