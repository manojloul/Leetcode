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
public:int i=0;
    TreeNode* solve(vector<int> in,vector<int> post,int s,int l)
    {
        if(s>l || i<0) return NULL;
        
        TreeNode* root=new TreeNode(post[i--]);
        int pos=s;
        while(in[pos]!=root->val)
            pos++;
        root->right=solve(in,post,pos+1,l);
        root->left=solve(in,post,s,pos-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        i=postorder.size()-1;
        return solve(inorder,postorder,0,inorder.size()-1);
    }
};