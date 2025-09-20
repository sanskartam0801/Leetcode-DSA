/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";

        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        ans += to_string(root->val) + ",";

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
                ans += to_string(node->left->val) + ",";
            } else {
                ans += "#,";
            }

            if (node->right) {
                q.push(node->right);
                ans += to_string(node->right->val) + ",";
            } else {
                ans += "#,";
            }
        }
        cout << ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        stringstream ss(data);
        string token;

        // Get root value
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (!getline(ss, token, ','))
                break;
            if (token != "#") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }

            // Right child
            if (!getline(ss, token, ','))
                break;
            if (token != "#") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));