class Solution {
public:
    int solve(vector<vector<int>>& matrix,int k)
    {
        int ans=0;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(matrix[i][j]>=k) ans++;
            }
        }
        return ans;
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int mx=0;
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                if(matrix[i][j]==1)
                {
                    int k=min(matrix[i-1][j-1],min(matrix[i][j-1],matrix[i-1][j]));
                    matrix[i][j]=k+1;
                    mx=max(mx,matrix[i][j]);
                }
            }
        }
        int count=0;
        for(int i=1;i<=mx;++i)
        {
            count+=solve(matrix,i);
        }
        return count;
    }
};