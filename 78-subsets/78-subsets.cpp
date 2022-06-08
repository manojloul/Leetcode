class Solution {
public:vector<vector<int>> ans;
    void solve(vector<int>&nums,vector<int> v,int i)
    {
        if(i==nums.size())
        {
            ans.push_back(v);
            return;
        }
        solve(nums,v,i+1);
        v.push_back(nums[i]);
        solve(nums,v,i+1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        solve(nums,v,0);
        return ans;
    }
};