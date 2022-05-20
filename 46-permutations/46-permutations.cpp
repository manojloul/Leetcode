class Solution {
public:
    map<vector<int>,int> st;
    vector<vector<int>> ans;
    
    void solve(vector<int> &nums,int pos)
    {
        if( pos==nums.size())
        {
            if(st.find(nums)==st.end())
                ans.push_back(nums);
            st[nums]++;
            return;
        }
        
        for(int i=0;i<nums.size();++i)
        {
            swap(nums[i],nums[pos]);
            solve(nums,pos+1);
            swap(nums[i],nums[pos]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        int pos=0;
        solve(nums,pos);
        sort(ans.begin(),ans.end());
        return ans;
    }
};