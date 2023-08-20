//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int lo(int arr[],int i,int j,int key)
	{
	    while(i<=j)
	    {
    	    int mid = (i+j)/2;
    	    if(arr[mid]==key)
    	    {
    	        j=mid-1;
    	    }
    	    else if(arr[mid] < key)
    	        i=mid+1;
    	    else
    	        j=mid-1;
    	        
	    }
	    return i;
	}
	int ro(int arr[],int i,int j,int key)
	{
	    while(i<=j)
	    {
    	    int mid = (i+j)/2;
    	    if(arr[mid]==key)
    	    {
    	        i=mid+1;
    	    }
    	    else if(arr[mid] < key)
    	        i=mid+1;
    	    else
    	        j=mid-1;
    	        
	    }
	    return j;
	}
	int count(int arr[], int n, int x) {
	    // code here
	    return ro(arr,0,n-1,x) - lo(arr,0,n-1,x)+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends