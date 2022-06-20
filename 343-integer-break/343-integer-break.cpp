class Solution {
public:
    int integerBreak(int n) {
        int dp[n+1];
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;++i)
        {
            int mn=INT_MIN;
            for(int j=1;j<i;++j)
            {
                mn=max(mn,j*(max(dp[i-j],(i-j))));
            }
            dp[i]=mn;
        }
        return dp[n];
    }
};