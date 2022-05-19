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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,int>> q;
        int mx=0;
        q.push({root,0});
        
        while(!q.empty())
        {
            int n=q.size();
            int first=0,last=0;
            for(int i=0;i<n;++i)
            {
                pair<TreeNode*,int> p=q.front();
                q.pop();
                
                TreeNode* t=p.first;
                int d=p.second;
                
                if(i==0)
                    first=d;
                if(i==n-1)
                    last=d;
                
                if(t->left)
                    q.push({t->left,(long long)2*d+1});
                if(t->right)
                    q.push({t->right,(long long)2*d+2});
                
            }
            mx=max(mx,last-first+1);
        }
        
        return mx;
    }
};