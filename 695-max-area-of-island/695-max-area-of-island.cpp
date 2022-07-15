class Solution {
public:
       void get_ans(int i,int j,vector<vector<int>>& grid,int n,int m,int& temp){
        if(i<0 || j<0 || i>=n || j>=m)return ;
        if(grid[i][j]==0){
            return;
        }
        if(grid[i][j]==1){
            grid[i][j]=0;
            temp++;
        }
        get_ans(i+1,j,grid,n,m,temp);
        get_ans(i-1,j,grid,n,m,temp);
        get_ans(i,j+1,grid,n,m,temp);
        get_ans(i,j-1,grid,n,m,temp);
        return ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    int temp=0;
                    get_ans(i,j,grid,n,m,temp);
                    ans=max(temp,ans);
                }
            }
        }
        return ans;
    }

};