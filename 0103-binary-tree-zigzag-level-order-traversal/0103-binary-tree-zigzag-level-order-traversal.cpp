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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool ltor= true;
        while(!q.empty()){
            int s= q.size();
            vector<int>level(s);
            for(int i=0; i<s; i++){
                TreeNode* curr= q.front();
                q.pop();
                int index= (ltor)?i:s-i-1;
                level[index]=curr->val;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
           
           ltor= !ltor;
            ans.push_back(level);
            
            }
           return ans;
    
   
    }
};