class Solution {
public: 
    bool helper(string s1, string s2, string s3,int n,int m,int len,int dp[101][101])
                {
                    if(len==0)
                        return true;
        if(dp[n][m]!=-1)
            return dp[n][m];
                    bool a=false,b=false;
                    
                    if(n-1>=0&&s1[n-1]==s3[len-1])
                        a=helper(s1,s2,s3,n-1,m,len-1,dp);
                     if(m-1>=0&&s2[m-1]==s3[len-1])
                        b=helper(s1,s2,s3,n,m-1,len-1,dp);
                    
                    return dp[n][m]=a||b;
                    
                }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        int dp[101][101];
        memset(dp,-1,sizeof(dp));
       return helper(s1,s2,s3,s1.size(),s2.size(),s3.size(),dp);
    }
};