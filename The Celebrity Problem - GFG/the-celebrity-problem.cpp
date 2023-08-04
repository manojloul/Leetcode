//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        vector<int> v;
        for(int i=0;i<n;++i)
        {
            int c =0;
            for(int j=0;j<n;++j)
             c +=M[i][j];
            if(c==0)
             v.push_back(i);
        }
        if(v.size()==0) return -1;
        
        for(int i=0;i<v.size();++i)
        {
            int t = v[i];
            int k=0;
            for(int j=0;j<n;++j)
             k += M[j][t];
            if(k==n-1) return t;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends