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
    TreeNode* solve(vector<int> &v ,int s,int l)
    {
        if(s>l) return NULL;
        
        TreeNode* root=new TreeNode(v[s]);
        
        int e=s+1;
        while(e<=l && v[e]<v[s])
            e++;
        root->left=solve(v,s+1,e-1);
        root->right=solve(v,e,l);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,0,preorder.size()-1);
    }
};