class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> pas;
        pas.push_back({1});
        if(n==1)
            return pas;
        pas.push_back({1,1});
        
        for(int i=2;i<n;++i)
        {
            vector<int> t;
            for(int j=0;j<=i;++j)
            {
                if(j==0 || j==i)
                    t.push_back(1);
                else
                    t.push_back(pas[i-1][j-1]+pas[i-1][j]);
            }
            pas.push_back(t);
        }
        return pas;
    }
};