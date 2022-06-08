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
public: TreeNode* ans=NULL;
    bool check(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root==NULL) return false;
        //cout<<root->val<<endl;
        if(root->val==p->val || root->val==q->val) return true;
        
        return check(root->left,p,q) || check(root->right,p,q);
    }
    void solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL) return;
        if(root->val==p->val || root->val==q->val){
            if(ans==NULL)
            ans= root; 
            return;
        }
        
        if(check(root->left,p,q) && check(root->right,p,q)) {
            if(ans==NULL)
            ans= root;
            return;
        }
        
        solve(root->left,p,q);
        solve(root->right,p,q);
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p,q);
        return ans;
    }
};