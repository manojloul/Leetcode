//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	long long int dp[4][3][26];
	long long solve(vector<vector<int>>&grid,int i,int j,int n)
	{
	    if(i<0|| j<0 || i>=4 || j>=3 ) return 0;
	    if(grid[i][j]==-1) return 0;
	    if(n==1) return 1;
	    if(dp[i][j][n]!=-1) return dp[i][j][n];
	    long long int s= solve(grid,i,j,n-1);
	    long long int l=solve(grid,i,j-1,n-1);
	    long long int r=solve(grid,i,j+1,n-1);
	    long long int d=solve(grid,i-1,j,n-1);
	    long long int u=solve(grid,i+1,j,n-1);
	    return dp[i][j][n]=s+l+r+d+u;
	}
	long long getCount(int n)
	{
	    memset(dp,-1,sizeof(dp));
		vector<vector<int>> grid{{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        long long ans = 0;
		for(int i=0;i<4;++i)
		{
		    for(int j=0;j<3;++j)
		    {
		        ans+=solve(grid,i,j,n);
		    }
		}
		return ans;
	}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends