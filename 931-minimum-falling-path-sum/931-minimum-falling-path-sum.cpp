class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       
        for(int i=1;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[0].size();++j)
            {
                int mn=INT_MAX;
                if(j-1>=0)
                    mn=min(mn,matrix[i-1][j-1]);
                if(j+1<matrix[0].size())
                    mn=min(mn,matrix[i-1][j+1]);
                mn=min(mn,matrix[i-1][j]);
                
                matrix[i][j]+=mn;
            }
        }
        
        int mn=INT_MAX;
        int l=matrix.size()-1;
        for(int i=0;i<matrix[0].size();++i)
            mn=min(mn,matrix[l][i]);
        return mn;
            
    }
};