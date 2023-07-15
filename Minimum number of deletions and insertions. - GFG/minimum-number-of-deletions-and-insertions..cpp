//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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
	int minOperations(string str1, string str2) 
	{ 
        int l = lcs(str1,str2);
        int l1=str1.size();
        int l2=str2.size();
        return l1-l+l2-l;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends