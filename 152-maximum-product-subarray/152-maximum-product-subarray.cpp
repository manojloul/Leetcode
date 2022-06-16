class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=nums[0];
        int mn=nums[0];
        int ans=nums[0];
        
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]<0) swap(mn,mx);
            
            mx=max(nums[i],nums[i]*mx);
            mn=min(nums[i],nums[i]*mn);
            ans=max(ans,mx);
        }
        return ans;
    }
};