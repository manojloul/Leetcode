class Solution {
public:
    int dp[51][51][51];
    int mod=1e9+7;
    int solve(int n,int m,int mx,int i,int j)
    {
        if(mx<0) return 0;
        if(i<0 || j<0 || i>=n || j>=m )
        {
            if(mx>=0) 
            return 1;
            return 0;
        }
        if(dp[i][j][mx]!=-1)
        {
            return dp[i][j][mx]%mod;
        }
        int l=solve(n,m,mx-1,i-1,j);
        int r=solve(n,m,mx-1,i+1,j);
        int u=solve(n,m,mx-1,i,j-1);
        int b=solve(n,m,mx-1,i,j+1);
        return dp[i][j][mx]=((long)l+r+u+b)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
         return solve(m,n,maxMove,startRow,startColumn);
         
    }
};