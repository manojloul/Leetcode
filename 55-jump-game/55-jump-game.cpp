class Solution {
public:
    bool canJump(vector<int>& nums) {
         int n=nums.size();
        if(n==1) return true;
         vector<int> dp(n,0);
         dp[0]=nums[0];
          if(dp[0]==0) return false;
        for(int i=1;i<n-1;++i)
        {
            dp[i]=max(nums[i],dp[i-1]-1);
            if(dp[i]==0) return false;
        }
        return true;
        
    }
};