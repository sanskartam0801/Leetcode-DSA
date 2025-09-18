class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root, nullptr});
        root->val = 0; // root must always be 0

        while (!q.empty()) {
            int size = q.size();
            unordered_map<TreeNode*, int> mp;
            vector<pair<TreeNode*,TreeNode*>> levelNodes;

            int total = 0;

            // process one level
            for (int i = 0; i < size; i++) {
                auto [node, parent] = q.front(); q.pop();
                levelNodes.push_back({node, parent});

                mp[parent] += node->val;
                total += node->val;

                if (node->left) q.push({node->left, node});
                if (node->right) q.push({node->right, node});
            }

            // update values
            for (auto [node, parent] : levelNodes) {
                node->val = total - mp[parent];
            }
        }
        return root;
    }
};
