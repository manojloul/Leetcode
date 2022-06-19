class Solution {
public:
    int solve(vector<int> &prices,int fee,int pos,int buy,int dp[][3])
    {
        if(pos==prices.size()) return 0;
        if(dp[pos][buy]!=-1) return dp[pos][buy];
        int profit;
        if(buy)
        {
            profit=max(-fee+prices[pos]+solve(prices,fee,pos+1,0,dp),solve(prices,fee,pos+1,1,dp));
            dp[pos][buy]=profit;
        }
        else
        {
            profit=max(-prices[pos]+solve(prices,fee,pos+1,1,dp),solve(prices,fee,pos+1,0,dp));
            dp[pos][buy]=profit;
        }
        return profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int dp[prices.size()+1][3];
        memset(dp,-1,sizeof(dp));
        return solve(prices,fee,0,0,dp);
    }
};