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
    bool solve(TreeNode* root,long long  left,long long right)
    {
        if(root==NULL) return true;
        
        int k=root->val;
        if(k<left || k>right) return false;
        
        
        return solve(root->left,left,(long)k-1) && solve(root->right,(long)k+1,right);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        long long left=LONG_MIN;
        long long right=LONG_MAX;
        return solve(root,left,right);
    }
};