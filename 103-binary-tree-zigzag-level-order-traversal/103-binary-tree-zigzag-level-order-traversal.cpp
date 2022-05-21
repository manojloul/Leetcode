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
        queue<TreeNode*> q;
        vector<int> v;
        int lvl=0;
        
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            
            if(temp==NULL)
            {
                if(lvl%2==0)
                    ans.push_back(v);
                else
                {
                    reverse(v.begin(),v.end());
                    ans.push_back(v);
                }
                
                if(q.empty()) break;
                lvl++;
                v.clear();
                q.push(NULL);
                continue;
            }
            
            v.push_back(temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return ans;
    }
};