class Solution {
public:
    int helper(TreeNode* root){
        if(!root) return 0;
        return 1 + helper(root->left) + helper(root->right);
    }

    int countNodes(TreeNode* root) {
        return helper(root);
    }
};
