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
    void kth(TreeNode*root , vector<int>&arr, int k){
         if(!root)return ;
        kth(root->left,arr, k);
        arr.push_back(root->val);
        kth(root->right,arr, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        kth(root,arr,k);
        // sort(arr.begin(), arr.end()); no need due to inorder
        return arr[k-1];
    }
};