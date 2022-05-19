class Solution {
public:vector<vector<int>> ans;
    void solve(vector<int> &can,int target,int pos,int &sum,vector<int> &v)
    {
        if(pos==can.size() && sum==target)
        {
            ans.push_back(v);
            return ;
        }
        if(pos==can.size() || sum>target)
            return;
        
        if(can[pos]+sum>target)
        {
            solve(can,target,pos+1,sum,v);
        }
        else
        {
            sum+=can[pos];
            v.push_back(can[pos]);
            solve(can,target,pos,sum,v);
            sum-=can[pos];
            v.pop_back();
            solve(can,target,pos+1,sum,v);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        int pos=0;
        vector<int> v;
        int sum=0;
        solve(can,target,pos,sum,v);
        return ans;
    }
};