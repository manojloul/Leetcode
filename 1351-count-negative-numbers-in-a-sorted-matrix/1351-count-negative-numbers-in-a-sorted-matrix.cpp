class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid[0].size();
        int n=grid.size();
        for(int i=0;i<n;++i)
        {
            int l=0,r=m-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(grid[i][mid]<0)
                    r=mid-1;
                else
                    l=mid+1;
            }
            ans+=(m-l);
        }
        return ans;
    }
};