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
    TreeNode* solve(vector<int> &in,int ins,int inl,vector<int> post,int pos,int pol)
    {
        if(pos>pol || ins>inl) return NULL;
        
        TreeNode* root=new TreeNode(post[pol]);
        int p=ins;
        while(in[p]!=post[pol])
            p++;
        root->left=solve(in,ins,p-1,post,pos,pos+p-ins-1);
        root->right=solve(in,p+1,inl,post,pos+p-ins,pol-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};