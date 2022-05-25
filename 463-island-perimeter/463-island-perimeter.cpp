class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                int row[4]={-1,1,0,0};
                int col[4]={0,0,-1,1};
                
                for(int k=0;k<4;++k)
                {
                    if(grid[i][j]==1){
                    if(i+row[k]<0 || i+row[k]>=n || j+col[k]<0 || j+col[k]>=m || grid[i+row[k]][j+col[k]]==0)
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};