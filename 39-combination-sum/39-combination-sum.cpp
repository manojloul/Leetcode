class Solution {
public:vector<vector<int>> ans;
    void solve(vector<int> &can,int &tar,int i,int sum,vector<int> &v)
    {
        if(i==can.size())
        {
            if(sum==tar)
                ans.push_back(v);
            return;
        }
        
        if(sum+can[i]<=tar)
        {
            v.push_back(can[i]);
            solve(can,tar,i,sum+can[i],v);
            v.pop_back();
            solve(can,tar,i+1,sum,v);
        }
        else
           solve(can,tar,i+1,sum,v); 
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<int> v;
        solve(can,target,0,0,v);
        return ans;
    }
};