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
public:int mx=INT_MIN;
    
    int solve(TreeNode* root)
    {
        if(root==NULL) return 0;
        
        int lsum=solve(root->left);
        int rsum=solve(root->right);
        if(lsum<0)
            lsum=0;
        if(rsum<0)
            rsum=0;
        mx=max(mx,lsum+rsum+root->val);
        
        return root->val+max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return mx;
    }
}; 