class Solution {
public: int dp[2001][2001];
    bool ispal(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &s,int start,int end)
    {
       if(start>=end ||ispal(s,start,end) )return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        int temp=INT_MAX;
        for(int k=start;k<end;++k)
        {
            // ans=1+solve(s,start,k)+solve(s,k+1,end);
//             if(dp[start][k]!=-1)ans+=dp[start][k];
//             else ans+=solve(s,start,k);
            
            if(ispal(s,start,k))
            {
              int ans=1+solve(s,k+1,end);
             temp=min(temp,ans);
            }
        }
        return dp[start][end]=temp;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.size()-1);
    }
};