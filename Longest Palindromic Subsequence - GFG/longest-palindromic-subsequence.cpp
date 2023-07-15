//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int lcs(string s1,string s2)
    {
        int l1=s1.size();
        int l2=s2.size();
        int dp[l1+1][l2+1];
        
        for(int i=0;i<=l1;++i)
        {
            for(int j=0;j<=l2;++j)
            {
                if(i==0 || j==0)
                dp[i][j]=0;
                else
                {
                    if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                    else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[l1][l2];
    }
    int longestPalinSubseq(string s) {
        string s1=s;
        reverse(s1.begin(),s1.end());
        return lcs(s,s1);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends