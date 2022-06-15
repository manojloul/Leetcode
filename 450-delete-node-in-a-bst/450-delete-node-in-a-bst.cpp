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
    TreeNode* check(TreeNode* root,int key)
    {
        if(root==NULL) return NULL;
        if(root->val>key) root->left= check(root->left,key);
        else if(root->val<key) root->right= check(root->right,key);
        else
        {
            if(root->left==NULL && root->right==NULL) return NULL;
            
            if(root->left==NULL)
            {
                TreeNode* t=root->right;
                while(t->left) t=t->left;
                root->val=t->val;
                root->right= check(root->right,t->val);
            }
            else
            {
                TreeNode* t=root->left;
                while(t->right) t=t->right;
                root->val=t->val;
                root->left=check(root->left,t->val);
            }
            
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return check(root,key);
      
    }
};