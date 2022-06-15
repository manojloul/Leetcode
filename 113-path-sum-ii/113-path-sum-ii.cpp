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
public:vector<vector<int>> ans;
    void solve(TreeNode* root,int target,vector<int> &v,int &sum)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
        {
            sum+=root->val;
            v.push_back(root->val);
            
            if(sum==target)
                ans.push_back(v);
            sum-=root->val;
            v.pop_back();
            return;
        }
        sum+=root->val;
        v.push_back(root->val);
        solve(root->left,target,v,sum);
//         sum-=root->val;
//         v.pop_back();
        
//         sum+=root->val;
//         v.push_back(root->val);
        solve(root->right,target,v,sum);
        sum-=root->val;
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        int sum=0;
        solve(root,targetSum,v,sum);
        return ans;
    }
};