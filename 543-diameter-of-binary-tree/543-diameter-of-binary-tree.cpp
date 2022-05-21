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
    int mx=INT_MIN;
    int maxdepth(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        return 1+max(maxdepth(root->left),maxdepth(root->right));
    }
    void solve(TreeNode* root)
    {
        if(root==NULL) return;
        
        solve(root->left);
        int k=maxdepth(root->left)+maxdepth(root->right);
        mx=max(k,mx);
        solve(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL ) return 0;
        solve(root);
        return mx;
    }
};