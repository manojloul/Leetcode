class Solution {
public:
    int solve(vector<int> &nums,int pos,int buy,int g,int dp[][3][3])
    {
        if(pos==nums.size()) return 0;
        
        if(dp[pos][buy][g]!=-1) return dp[pos][buy][g];
        int profit;
        if(buy==1 && g==1)
        {
            profit=solve(nums,pos+1,1,0,dp);
        }
        else if(buy==1 && g==0)
        {
            profit=max(-nums[pos]+solve(nums,pos+1,0,0,dp),solve(nums,pos+1,1,0,dp));
            dp[pos][buy][g]=profit;
        }
        else
        {
            profit=max(nums[pos]+solve(nums,pos+1,1,1,dp),solve(nums,pos+1,0,0,dp));
            dp[pos][buy][g]=profit;
        }
        
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int dp[5001][3][3];
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,1,0,dp);
    }
};