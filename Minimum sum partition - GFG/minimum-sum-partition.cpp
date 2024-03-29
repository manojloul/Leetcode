//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0;i<n;++i)
	     sum+=arr[i];
	    
	    bool dp[n+1][sum+1];
	    
	    for(int i=0;i<=n;++i)
	    {
	        for(int j=0;j<=sum;++j)
	        {
	            if(i==0) dp[i][j]=false;
	            if(j==0) dp[i][j]=true;
	        }
	    }
	    for(int i=1;i<=n;++i)
	    {
	        for(int j=1;j<=sum;++j)
	        {
	            if(arr[i-1] <= j)
	            {
	                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
	            }
	            else
	             dp[i][j]=dp[i-1][j];
	        }
	    }
	    vector<int> v;
	    
	    for(int i=0;i<=sum/2;++i)
	    {
	        if(dp[n][i]==true) v.push_back(i);
	    }
	    int mn =sum;
	    
	    for(int i=0;i<v.size();++i)
	     mn= min(mn,sum-2*v[i]);
	     return mn;
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

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends