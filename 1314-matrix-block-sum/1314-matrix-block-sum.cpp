class Solution {
public:
    vector<vector<int>> mat;
    void sum(vector<vector<int>> mat1)
    {
        mat=mat1;
        int m=mat1[0].size();
        int n=mat1.size();
        for(int i=1;i<m;++i)
            mat[0][i]+=mat[0][i-1];
        for(int i=1;i<n;++i)
            mat[i][0]+=mat[i-1][0];
        
        for(int i=1;i<n;++i)
        {
            for(int j=1;j<m;++j)
            {
                mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
            }
        }
    }
    int solve(int row1, int row2, int col1, int col2) {
        int a=0,b=0,c=0;
        if(row1-1>=0 && col1-1>=0)
        {
            a=mat[row1-1][col1-1];
            b=mat[row1-1][col2];
            c=mat[row2][col1-1];
            return mat[row2][col2]-b-c+a;
        }
        else if(row1-1>=0)
        {
            b=mat[row1-1][col2];
            return mat[row2][col2]-b;
        }
        else if(col1-1>=0)
        {
            c=mat[row2][col1-1];
            return mat[row2][col2]-c;
        }
        return mat[row2][col2];
        
        
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        sum(mat);
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> ans=mat;
        int rs,re,cs,ce;
        for(int i=0;i<n;++i)
        {
            if(i-k<=0) rs=0;
            else rs=i-k;
            
            if(i+k<n) re=i+k;
            else re=n-1;
            
            for(int j=0;j<m;++j)
            {
                if(j-k<=0) cs=0;
                else cs=j-k;
                
                if(j+k<m) ce=j+k;
                else ce=m-1;
                
                ans[i][j]=solve(rs,re,cs,ce);
            }
        }
        return ans;
    }
};