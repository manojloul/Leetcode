class Solution {
public:
    int dp[1001][1001];
    int lcs(string &s1,string &s2,int n,int m)
    {
        if(n==s1.size() || m==s2.size()) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n]==s2[m])
        {
            return dp[n][m]=1+lcs(s1,s2,n+1,m+1);
        }
        else
            return dp[n][m]=max(lcs(s1,s2,n+1,m),lcs(s1,s2,n,m+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return lcs(text1,text2,0,0);
    }
};