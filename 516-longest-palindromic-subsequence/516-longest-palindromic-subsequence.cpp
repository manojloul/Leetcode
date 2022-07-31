class Solution {
public:
    int dp[1001][1001];
    int lcs(string &x,string &y,int n,int m)
    {
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(x[n-1]==y[m-1])
            return dp[n][m]=1+lcs(x,y,n-1,m-1);
        else
            return dp[n][m]=max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        string s1=s;
        reverse(s1.begin(),s1.end());
        return lcs(s,s1,s.size(),s.size());
    }
};