class Solution {
public:int count=0;
    bool row_valid(vector<vector<int>> &mat,int i,int j,int n)
    {
        for(int c=0;c<n;++c)
        {
            if(mat[i][c]==1)
                return false;
        }
        return true;
    }
    bool col_valid(vector<vector<int>> &mat,int i,int j,int n)
    {
        for(int r=0;r<n;++r)
        {
            if(mat[r][j]==1)
                return false;
        }
        return true;
    }
    
    bool diagonal(vector<vector<int>> &mat,int i,int j,int n)
    {
        int r=i,c=j;
        while(r>=0 && c>=0)
        {
            if(mat[r][c]==1)
                return false;
            r--;
            c--;
        }
        r=i;
        c=j;
        while(r<n && c<n)
        {
            if(mat[r][c]==1)
                return false;
            r++;
            c++;
        }
        r=i;
        c=j;
        while(r<n && c>=0)
        {
            if(mat[r][c]==1)
                return false;
            r++;
            c--;
        }
        r=i;
        c=j;
        while(r>=0 && c<n)
        {
            if(mat[r][c]==1)
                return false;
            r--;
            c++;
        }
        return true;
    }
    bool isvalid(vector<vector<int>> &mat,int i,int j,int n)
    {
        if(row_valid(mat,i,j,n) && col_valid(mat,i,j,n) && diagonal(mat,i,j,n))
            return true;
        return false;
    }
    void solve(vector<vector<int>>& mat,int col,int n)
    {
        if(col==n)
        {
            count++;
            return;
        }
        
        for(int i=0;i<n;++i)
        {
            if(isvalid(mat,i,col,n))
            {
                mat[i][col]=1;
                solve(mat,col+1,n);
                mat[i][col]=0;
            }
        }
    }
    int totalNQueens(int n) {
      vector<vector<int>> mat;
      vector<int> v(n,0);
      for(int i=0;i<n;++i)
      {
          mat.push_back(v);
      }
        
        int col=0;
        solve(mat,col,n);
        
        return count;
    }
};