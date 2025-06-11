class Solution {
public:
    void dfs(TreeNode* node, int level, vector<int>& res) {
        if (!node) return;

        // If this is the first node we're visiting at this level
        if (level == res.size()) {
            res.push_back(node->val);
        }

        // Go right first
        dfs(node->right, level + 1, res);
        dfs(node->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};
