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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode* t=q.front();
            q.pop();
            if(t==NULL)
            {
                if(q.empty()) break;
                
                q.push(NULL);
                continue;
            }
            if(q.front()==NULL) ans.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        
        return ans;
    }
};