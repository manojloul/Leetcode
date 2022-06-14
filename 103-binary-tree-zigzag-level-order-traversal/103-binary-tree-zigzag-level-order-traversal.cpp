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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int l=0;
        while(!q.empty())
        {
            TreeNode* t=q.front();
            q.pop();
            if(t==NULL)
            {
                if(l%2==0)
                    ans.push_back(temp);
                else
                {
                    reverse(temp.begin(),temp.end());
                    ans.push_back(temp);
                }
                if(q.empty()) break;
                l++;
                temp.clear();
                q.push(NULL);
                continue;
            }
            temp.push_back(t->val);
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        return ans;
    }
};