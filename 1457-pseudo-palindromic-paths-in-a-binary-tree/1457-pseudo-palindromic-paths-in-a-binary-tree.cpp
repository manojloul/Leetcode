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
public:int count=0;
    
   
    void solve(TreeNode* root,vector<int> v)
    {
        if(root==NULL)
            return;
        v[root->val]++;
        if(root->left==NULL && root->right==NULL)
        {
            int c=0;
            for(int i=1;i<=9;++i)
            {
                
                if(v[i]%2!=0)
                    c++;
            }
            
            if(c<=1)
                count++;
            return;
        }
        solve(root->left,v);
        solve(root->right,v);
        
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> v(10,0);
        solve(root,v);
        return count;
    }
};