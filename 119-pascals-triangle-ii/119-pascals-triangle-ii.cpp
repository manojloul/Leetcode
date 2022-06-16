class Solution {
public:
    vector<int> getRow(int row) {
        vector<vector<int>> v;
        v.push_back({1});
        v.push_back({1,1});
        if(row==0) return {1};
        if(row==1) return {1,1};
        
        for(int i=2;i<=row;++i)
        {
            vector<int> temp;
            for(int j=0;j<=i;++j)
            {
                if(j==0 || j==i) temp.push_back(1);
                else
                    temp.push_back(v[i-1][j]+v[i-1][j-1]);
            }
            v.push_back(temp);
        }
        return v[row];
    }
};