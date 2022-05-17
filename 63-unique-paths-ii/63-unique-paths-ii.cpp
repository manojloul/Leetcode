class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1 || grid[grid.size()-1][grid[0].size()-1]==1)return 0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j]==1)
                    grid[i][j]=-1;
            }
        }
        
        grid[0][0]=1;
       
        for(int i=1;i<grid.size();++i)
        {
            if(grid[i][0]==0 && grid[i-1][0]==1)
                grid[i][0]=1;
            else
                grid[i][0]=-1;
        }
        
        for(int i=1;i<grid[0].size();++i)
        {
            if(grid[0][i]==0 && grid[0][i-1]==1)
                grid[0][i]=1;
            else
                grid[0][i]=-1;
        }
       
        for(int i=1;i<grid.size();++i)
        {
            for(int j=1;j<grid[i].size();++j)
            {
                if(grid[i][j]!=-1)
                {
                    if(grid[i-1][j]==-1 && grid[i][j-1]==-1)
                        grid[i][j]=-1;
                    else if(grid[i-1][j]==-1)
                        grid[i][j]=grid[i][j-1];
                    else if(grid[i][j-1]==-1)
                        grid[i][j]=grid[i-1][j];
                    else
                        grid[i][j]=grid[i-1][j]+grid[i][j-1];
                        
                }
            }
        }
        if(grid[grid.size()-1][grid[0].size()-1]==-1)
            return 0;
        return grid[grid.size()-1][grid[0].size()-1];
    }
};