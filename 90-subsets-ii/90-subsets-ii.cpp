class Solution {
public:map<vector<int>,int>mp;
    vector<vector<int>> ans;
    void solve(vector<int> &nums,int pos,vector<int> v)
    {
        if(pos==nums.size())
        {
            if(mp.find(v)==mp.end())
                ans.push_back(v);
            mp[v]++;
            return;
        }
        solve(nums,pos+1,v);
        v.push_back(nums[pos]);
        solve(nums,pos+1,v);
        v.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        solve(nums,0,v);
        
        return ans;
    }
};