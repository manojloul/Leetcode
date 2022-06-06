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
    bool issame(TreeNode* t1,TreeNode* t2)
    {
        if(t1==NULL && t2==NULL) return true;
        else if(t1==NULL || t2==NULL) return false;
        
        if(t1->val!=t2->val) return false;
        
        return issame(t1->left ,t2->left) && issame(t1->right,t2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(issame(temp,subRoot)) return true;
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return false;
    }
};