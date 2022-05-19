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
    bool static cmp(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.first==p2.first)
            return p1.second<p2.second;
        return p1.first<p2.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        q.push({0,NULL});
        int l=0;
        while(!q.empty())
        {
            pair<int,TreeNode*> p=q.front();
            q.pop();
            if(p.second==NULL)
            {
                l++;
                if(q.empty()) break;
                q.push({0,NULL});
                continue;
            }
            mp[p.first].push_back({l,p.second->val});
            
            if(p.second->left)
             q.push({p.first-1,p.second->left});
            if(p.second->right)
             q.push({p.first+1,p.second->right});
        }
        vector<vector<int>> ans;
        for(auto it:mp)
        {
            vector<pair<int,int>> v=it.second;
            
            vector<int> temp;
            sort(v.begin(),v.end(),cmp);
            for(int i=0;i<v.size();++i)
            {
                temp.push_back(v[i].second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};