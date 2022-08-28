class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat[0].size();
        int n=mat.size();
        
        
        for(int i=0;i<m;++i)
        {
            vector<int> v;
            int s=0;
            int r=i;
            while(s<n && r<m)
            {
                v.push_back(mat[s][r]);
                s++;
                r++;
            }
            sort(v.begin(),v.end());
            s=0;
            r=i;
            int k=0;
            while(s<n && r<m)
            {
                mat[s][r]=v[k++];
                s++;
                r++;
            }
        }
        
        for(int i=1;i<n;++i)
        {
            vector<int> v;
            int s=i;
            int r=0;
            while(s<n && r<m)
            {
                v.push_back(mat[s][r]);
                s++;
                r++;
            }
            sort(v.begin(),v.end());
            s=i;
            r=0;
            int k=0;
            while(s<n && r<m)
            {
                mat[s][r]=v[k++];
                s++;
                r++;
            }
        }
        return mat;
    }
};