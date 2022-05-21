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
    int mx(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        return 1+max(mx(root->left),mx(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
        
        if(abs(mx(root->left)-mx(root->right))>1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};