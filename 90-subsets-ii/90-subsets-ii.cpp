class Solution {
public:vector<vector<int>> ans;
       map<vector<int>,int> mp;
    void solve(vector<int> &arr,vector<int> v,int i)
    {
        if(i==arr.size())
        {
            if(mp.find(v)==mp.end())
                ans.push_back(v);
            mp[v]++;
            return;
        }
        
        solve(arr,v,i+1);
        v.push_back(arr[i]);
        solve(arr,v,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        solve(nums,v,0);
        return ans;
    }
};