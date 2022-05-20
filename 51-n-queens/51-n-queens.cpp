class Solution {
public:vector<vector<string> > ans;
    vector<vector<int>> grid;
    bool isrow(vector<vector<int>> &grid,int row,int col)
    {
        int n=grid.size();
        for(int i=0;i<n;++i)
        {
            if(i!=col)
            {
                if(grid[row][i]==1)
                    return false;
            }
        }
        return true;
    }
    bool iscol(vector<vector<int>> &grid,int row,int col)
    {
        int n=grid.size();
        for(int i=0;i<n;++i)
        {
            if(i!=row)
            {
                if(grid[i][col]==1)
                    return false;
            }
        }
        return true;
    }
    bool isdig(vector<vector<int>> &grid,int row,int col)
    {
        int n=grid.size();
        int i=row-1;
        int j=col-1;
        while(i>=0 && j>=0)
        {
            if(grid[i][j]==1)
                return false;
            i--;
            j--;
        }
        i=row+1;
        j=col+1;
        while(i<n && j<n)
        {
            if(grid[i][j]==1)
                return false;
            i++;
            j++;
        }
        i=row+1;
        j=col-1;
        while(i<n && j>=0)
        {
            if(grid[i][j]==1)
                return false;
            i++;
            j--;
        }
        i=row-1;
        j=col+1;
        while(i>=0 && j<n)
        {
            if(grid[i][j]==1)
                return false;
            i--;
            j++;
        }
        return true;
    }
    
    void solve(vector<vector<int>> &grid,int row)
    {
        int n=grid.size();
        if(row==n)
        {
            vector<string> v;
            for(int i=0;i<n;++i)
            {
                string s="";
                for(int j=0;j<n;++j)
                {
                    if(grid[i][j]==1)
                        s+='Q';
                    else
                        s+='.';
                }
                v.push_back(s);
            }
            ans.push_back(v);
            return;
        }
        
        for(int i=0;i<n;++i)
        {
            if(isrow(grid,row,i) && iscol(grid,row,i)  && isdig(grid,row,i))
            {
                grid[row][i]=1;
                solve(grid,row+1);
                grid[row][i]=0;
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        for(int i=0;i<n;++i)
        {
            vector<int> v;
            for(int j=0;j<n;++j)
            {
                v.push_back(0);
            }
            grid.push_back(v);
        }
        int row=0,col=0;
        solve(grid,row);
        return ans;
    }
};