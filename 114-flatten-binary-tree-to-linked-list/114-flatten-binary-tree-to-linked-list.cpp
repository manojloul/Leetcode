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
    TreeNode* solve(TreeNode* root)
{
     if(!root) return NULL;
    TreeNode* l=solve(root->left);
    TreeNode* r=solve(root->right);
    
    if(l)
    {
        TreeNode* temp=l;
        root->left=NULL;
        while(temp->right) temp=temp->right;
        temp->right=r;
        root->right=l;
    }
    return root;
}
    void flatten(TreeNode* root) {
        solve(root);
    }
};