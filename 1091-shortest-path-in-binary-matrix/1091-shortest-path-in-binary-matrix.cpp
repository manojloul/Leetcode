class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 ||grid[n-1][n-1]==1) return -1;
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(grid[i][j]==1) grid[i][j]==-1;
            }
        }
        grid[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;
            for(int i=-1;i<=1;++i)
            {
                for(int j=-1;j<=1;++j)
                {
                    if(i==0 && j==0) continue;
                    if(i+r>=0 && i+r<n && j+c>=0 && j+c<n)
                    {
                        if(grid[i+r][j+c]==0)
                        {
                            grid[i+r][j+c]=grid[r][c]+1;
                            q.push({i+r,j+c});
                        }
                    }
                }
            }
        }
        if(grid[n-1][n-1]==0) return -1;
        return grid[n-1][n-1];
    
    }
};