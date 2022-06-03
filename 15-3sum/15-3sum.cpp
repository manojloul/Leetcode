class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i)
        {
            
            int l=i+1;
            int r=nums.size()-1;
            int tar=0-nums[i];
            while(l<r)
            {
                if(nums[l]+nums[r]==tar)
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    int k=nums[l];
                    while(l<r && nums[l]==k)
                        l++;
                }
                
                if(nums[l]+nums[r]<tar)
                    l++;
                else
                    r--;
            }
            
            while(i+1<nums.size() && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};