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
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        mpd(root,maxi);
        return maxi;
    }
    int mpd(TreeNode* node, int &maxi){
        if(node==NULL)return 0;
        int ls= max(0,mpd(node->left,maxi));
        int rs= max(0, mpd(node->right, maxi));
        maxi= max(maxi, ls+rs+node->val);
        return node->val + max(ls,rs);
    }
};