//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int mx =0;
        int ans = 0;
        int o =0;
       for(int i=0;i<n;++i)
       {
           if(a[i]==1) o++; 
           if(a[i]==0) ans+=1;
           else ans-=1;
           
           mx=max(mx,ans);
           if(ans<0) ans=0;
       }
       return mx+o;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends