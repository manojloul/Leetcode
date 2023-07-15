//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public
    int lcs(string s1,string  s2)
    {
        int l1=s1.size();
        int l2=s2.size();
        
        int dp[l1+1][l2+1];
        
        for(int i=0;i<=l1;++i)
        {
            for(int j=0;j<=l2;++j)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
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
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        int l=lcs(X,Y);
        return m+n-l;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends