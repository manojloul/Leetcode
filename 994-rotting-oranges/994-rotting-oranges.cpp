class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int t=0;
        
        while(!q.empty())
        {
            int n=q.size();
            for(int ii=0;ii<n;++ii)
            {
                pair<int,int> p=q.front();
                q.pop();
                
                int i=p.first;
                int j=p.second;
                int row[4]={-1,1,0,0};
                int col[4]={0,0,-1,1};
                
                for(int l=0;l<4;++l)
                {
                    if(i+row[l]<0 || i+row[l]>=grid.size() || j+col[l]<0 || j+col[l]>=grid[0].size() ) continue;
                    if(grid[i+row[l]][j+col[l]]==1) 
                    {
                        grid[i+row[l]][j+col[l]]=2;
                        q.push({i+row[l],j+col[l]});
                    }
                }
            }
            if(q.size()>0)
            t++;
        }
        
        
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        
        return t;
    }
};