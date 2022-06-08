class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==2) return min(cost[0],cost[1]);
        cost.push_back(0);
        int dp[n+1];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<=n;++i)
        {
            dp[i]=cost[i]+min(dp[i-2],dp[i-1]);
        }
        return dp[n];  
    }
};