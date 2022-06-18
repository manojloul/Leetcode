class Solution {
public:
    int dp[20];
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        dp[0]=1;
        dp[1]=1;
        solve(n);
        return dp[n];
    }
    
    int solve(int n)
    {
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            int left=solve(i-1);
            int right=solve(n-i);
            ans+=left*right;
        }
        return dp[n]=ans;
    }
};