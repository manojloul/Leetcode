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
    unordered_map<int,int> mp;
    bool ans=false;
    
    void solve(TreeNode* root,int k)
    {
        if(!root) return;
        
        solve(root->left,k);
        
        if(mp.find(k-root->val)!=mp.end())
        {
            ans=true;
            return;
        }
        mp[root->val]++;
        
        solve(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        solve(root,k);
        return ans;
    }
};