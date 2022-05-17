class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i)
        {
            int t=0-nums[i];
            int s=i+1;
            int e=nums.size()-1;
            
            while(s<e)
            {
                if(nums[s]+nums[e]==t)
                {
                    ans.insert({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }
                else if(nums[s]+nums[e]<t)
                {
                    s++;
                }
                else
                    e--;
            }
        }
        for(auto it:ans)
            v.push_back(it);
        return v;
    }
};