class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans=0;
        
        for(int i=0;i<grid.size();++i)
        {
            int f=0;
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==1)
                    f++;
            }
            if(f>1){
             for(int j=0;j<grid[0].size();++j)
                 if(grid[i][j]==1) grid[i][j]=2;
            }
        }
        for(int i=0;i<grid[0].size();++i)
        {
            int f=0;
            for(int j=0;j<grid.size();++j)
            {
                if(grid[j][i]==1 ||grid[j][i]==2)
                    f++;
            }
            if(f>1){
             for(int j=0;j<grid.size();++j)
                 if(grid[j][i]==1) grid[j][i]=2;
            }
        }
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==2)
                    ans++;
            }
        }
        return ans;
    }
};