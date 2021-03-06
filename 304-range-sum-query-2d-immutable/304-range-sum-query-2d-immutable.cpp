class NumMatrix {
public:vector<vector<int>> mat,mat1;
    NumMatrix(vector<vector<int>>& matrix) {
        mat=matrix;
        int m=matrix[0].size();
        int n=matrix.size();
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
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
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
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */