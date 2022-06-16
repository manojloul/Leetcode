class Solution {
public:
    int solve(vector<int> &nums)
    {
        int sum=0;
        int mx=INT_MIN;
        
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            mx=max(mx,sum);
            if(sum<0) sum=0;
        }
        return mx;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans=solve(nums);
        int sum=0;
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            nums[i]=-nums[i];
        }
        int a=solve(nums);
        if(a+sum==0) return ans;
        return max(ans,a+sum);
    }
};