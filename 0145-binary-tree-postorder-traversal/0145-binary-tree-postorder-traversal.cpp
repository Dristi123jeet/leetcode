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
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int>postorder;
       if(root==NULL)return postorder;
       stack<TreeNode*>st1, st2;
       st1.push(root);
       while(!st1.empty()){
        TreeNode* node= st1.top();
        st1.pop();
        st2.push(node);
        if(node->left)st1.push(node->left);
        if(node->right)st1.push(node->right);
       } 
       while(!st2.empty()){
        TreeNode*node=st2.top();
        st2.pop();
        postorder.push_back(node->val);
       }
       return postorder;
    }
};