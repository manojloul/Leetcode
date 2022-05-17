class Solution {
public:
    int uniquePaths(int m, int n) {
        int ans[m][n];
        memset(ans,0,sizeof(ans));
        
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==0 || j==0)
                    ans[i][j]=1;
            }
        }
        
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                ans[i][j]=ans[i-1][j]+ans[i][j-1];
            }
        }
        return ans[m-1][n-1];
    }
};