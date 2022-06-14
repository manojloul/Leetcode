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
public: int pos=0;
    TreeNode* solve(vector<int> &pre,vector<int> &in,int l,int r)
    {
        if(l>r || pos>= pre.size()) return NULL;
        int k=pre[pos];
        TreeNode* root=new TreeNode(pre[pos++]);
        int lr,rl;
        for(int i=l;i<=r;++i)
        {
            if(in[i]==k)
            {
                lr=i-1;
                rl=i+1;
                break;
            }
        }
        root->left=solve(pre,in,l,lr);
        root->right=solve(pre,in,rl,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};