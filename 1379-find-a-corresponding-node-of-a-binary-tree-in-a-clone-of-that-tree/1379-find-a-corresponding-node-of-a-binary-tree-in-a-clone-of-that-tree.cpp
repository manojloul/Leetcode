/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:TreeNode* temp;
    void solve(TreeNode* root,TreeNode* target)
    {
        if(root->val==target->val)
        {
            temp= root;
            return;
        }
        if(root->left)
            solve(root->left,target);
        if(root->right)
           solve(root->right,target);
        
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        solve(cloned,target);
        return temp;
    }
};