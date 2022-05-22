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
    TreeNode* solve(vector<int> pre,vector<int> in,int pres,int prel,int ins,int inl)
    {
        if(pres>prel ||ins>inl) return NULL;
        
        TreeNode* root=new TreeNode(pre[pres]);
        
        int pos=ins;
        while(in[pos]!=pre[pres])
            pos++;
        root->left= solve(pre,in,pres+1,pres-ins+pos,ins,pos-1);
        root->right=solve(pre,in,pres-ins+pos+1,prel,pos+1,inl);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};