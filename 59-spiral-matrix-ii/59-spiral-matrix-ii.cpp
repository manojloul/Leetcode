class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int left=0,right=n-1;
        int upper=0,bottom=n-1;
        int r=0;
        int p=1;
        while(left<=right && upper<=bottom)
        {
            if(r==0)
            {
                for(int i=left;i<=right;++i)
                    ans[upper][i]=p++;
                upper++;
                r++;
            }
            else if(r==1)
            {
                for(int i=upper;i<=bottom;++i)
                    ans[i][right]=p++;
                right--;
                r++;
            }
            else if(r==2)
            {
                for(int i=right;i>=left;--i)
                    ans[bottom][i]=p++;
                bottom--;
                r++;
            }
            else if(r==3)
            {
                for(int i=bottom;i>=upper;--i)
                    ans[i][left]=p++;
                left++;
                r++;
            }
            r=r%4;
        }
        
        return ans;
    }
};