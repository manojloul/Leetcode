class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<m;++j)
                swap(matrix[i][j],matrix[j][i]);
        }
        int i=0,j=m-1;
        while(i<j)
        {
            for(int k=0;k<n;++k)
                swap(matrix[k][i],matrix[k][j]);
            i++;
            j--;
        }
    }
};