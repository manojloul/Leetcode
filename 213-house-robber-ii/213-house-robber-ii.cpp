class Solution {
public:
    int rob(vector<int>& num) {
        int n=num.size();
        if(n==1) return num[0];
        if(n==2) return max(num[0],num[1]);
        if(n==3) return max(num[0],max(num[1],num[2]));
        
        vector<int> dp(n+1,0);
        dp[0]=num[0];
        dp[1]=num[1];
        dp[2]=dp[0]+num[2];
        for(int i=3;i<n-1;++i)
        {
            dp[i]=num[i]+max(dp[i-2],dp[i-3]);
        }
        int mx=max(dp[n-3],dp[n-2]);
        dp.clear();
        dp[1]=num[1];
        dp[2]=num[2];
        dp[3]=dp[1]+num[3];
        for(int i=4;i<n;++i)
        {
            dp[i]=num[i]+max(dp[i-2],dp[i-3]);
        }
        return max(mx,max(dp[n-1],dp[n-1]));
    }
};