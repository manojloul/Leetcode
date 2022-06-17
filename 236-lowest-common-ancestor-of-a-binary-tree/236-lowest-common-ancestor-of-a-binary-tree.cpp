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
public:
    bool find(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL) return false;
        
        if(root==p ||root==q) return true;
        
        return find(root->left,p,q) || find(root->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==p || root==q) return root;
        
        bool lt=find(root->left,p,q);
        bool rt=find(root->right,p,q);
    
        if(lt && rt) return root;
        
        if(lt)
            return lowestCommonAncestor(root->left,p,q);
        else
            return lowestCommonAncestor(root->right,p,q);
    }
};