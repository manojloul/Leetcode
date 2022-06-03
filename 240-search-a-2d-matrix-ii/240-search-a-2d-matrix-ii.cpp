class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat[0].size()-1;
        for(int i=0;i<mat.size();++i)
        {
            if(target>= mat[i][0] && target<=mat[i][m])
            {
                for(int j=0;j<=m;++j)
                    if(mat[i][j]==target) return true;
            }
        }
        return false;
    }
};