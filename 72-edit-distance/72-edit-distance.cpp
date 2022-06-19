class Solution {
public:
    int lcs(string s1,string s2)
    {
        int l1=s1.size();
        int l2=s2.size();
        
        int dp[l1+1][l2+1];
        
        for(int i=0;i<l1+1;++i)
        {
            for(int j=0;j<l2+1;++j)
             {
                 if(i==0 || j==0) 
                     dp[i][j]=max(i,j);
             }
        }
        
        for(int i=1;i<=l1;++i)
        {
            for(int j=1;j<=l2;++j)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }
       
        return dp[l1][l2];
    }
    int minDistance(string word1, string word2) {
        int l=lcs(word2,word1);
       
        return l;
    }
};